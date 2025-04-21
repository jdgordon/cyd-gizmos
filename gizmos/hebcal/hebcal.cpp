#include <Arduino.h>
#include <HTTPClient.h>
#include "TimeLib.h"
#include "ArduinoJson.h"

#include "hebcal.h"

static char urlBuf[512];

char* GetHebCalUrl(bool forZmanin, TimeElements today, TimeElements tomorrow) {
    int rc = sprintf(urlBuf, "http://www.hebcal.com/%scfg=json&geonameid=2158177&", forZmanin ? "zmanim?" : "hebcal?v=1&");
    if (forZmanin) {
        sprintf(&urlBuf[rc], "date=%04d-%02d-%02d", today.Year + 1970, today.Month, today.Day);
    } else {
        sprintf(&urlBuf[rc], "start=%04d-%02d-%02d&end=%04d-%02d-%02d&maj=on&o=on&i=on&c=on&M=on&d=on", 
            today.Year + 1970, today.Month, today.Day, tomorrow.Year + 1970, tomorrow.Month, tomorrow.Day);
    }
    Serial.println(urlBuf);
    return urlBuf;
}

time_t get_nightfall_time(String tzeit85deg) {
    TimeElements tziet;
    int yyyy, mm, dd, hour, min, sec;
    int rc = sscanf(tzeit85deg.c_str(), "%4d-%02d-%02dT%02d:%02d:%02d", &yyyy, &mm, &dd, &hour, &min, &sec);
    if (rc != 6) {
        Serial.printf("sscanf() failed: %d\n", rc);
    }

    tziet.Year = yyyy - 1970;
    tziet.Month = mm;
    tziet.Day = dd;
    tziet.Hour = hour;
    tziet.Minute = min;
    tziet.Second = sec;
    return makeTime(tziet) - 10*3600;
}


HebCalVals ReloadHebCal(time_t unixtime) {
    HebCalVals outVals{};
    TimeElements today, tomorrow;
    breakTime(unixtime, today);
    breakTime(unixtime+86400, tomorrow);
    HTTPClient http;
    http.begin(GetHebCalUrl(false, today, tomorrow));
    int httpResponseCode = http.GET();
    
    if (httpResponseCode >= 400) {
        http.end();
        outVals.error = 1;
        return outVals;
    }
    
    auto hebcalData = http.getString();
    http.end();
    Serial.println(hebcalData);

    http.begin(GetHebCalUrl(true, today, tomorrow));
    httpResponseCode = http.GET();
    
    if (httpResponseCode >= 400) {
        http.end();
        outVals.error = 2;
        return outVals;
    }
    auto zmanim = http.getString();
    http.end();
    Serial.println(zmanim);

    // get the tzeit85deg time to figure out which day to use
    JsonDocument jdoc;
    DeserializationError error;
    if ((error = deserializeJson(jdoc, zmanim))) {
        outVals.error = 3;
        return outVals;
    }
    auto tzeit85deg = jdoc["times"]["tzeit85deg"].as<String>();
    auto nightfall = get_nightfall_time(tzeit85deg);

    if (unixtime < nightfall) {
        // we want todays hebrew date data
        sprintf(urlBuf, "%04d-%02d-%02d", today.Year + 1970, today.Month, today.Day);
        outVals.isNighttime = false;
        outVals.next_update_secs = nightfall-unixtime;
    } else {
        // we want tomorrows hebrew date data
        outVals.isNighttime = true;
        sprintf(urlBuf, "%04d-%02d-%02d", tomorrow.Year + 1970, tomorrow.Month, tomorrow.Day);
        tomorrow.Hour = 0;
        tomorrow.Minute = 1;
        tomorrow.Second = 0;
        outVals.next_update_secs = makeTime(tomorrow)-unixtime;
    }
    char *todayStr = urlBuf;

    if ((error = deserializeJson(jdoc, hebcalData))) {
        outVals.error = 4;
        return outVals;
    }

    for (JsonObject item : jdoc["items"].as<JsonArray>()) {
        String category = item["category"];
        Serial.printf("cat: %s, date: %s==%s\n", category.c_str(),item["date"].as<String>().c_str(), todayStr );
        if (category.equals("hebdate") && item["date"].as<String>().equals(todayStr)) {
            outVals.hDate = item["hdate"].as<String>();
        } else if (category.equals("omer") && item["date"].as<String>().equals(todayStr)) {
            sscanf(item["title_orig"].as<String>().c_str(), "Omer %d", &outVals.DayOfOmer);
        }
    }

    return outVals;
}