#include <memory>
#include <Arduino.h>
#include "secrets.h"

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "HTTPClient.h"
#include "ArduinoJson.h"
#include <NTPClient.h>
#include "TimeLib.h"

#include "hebcal.h"

enum State {
    State_Waiting = 0,
    State_ConnectToWifi,
    State_WifiConnected,
};

static enum State current_state = State_Waiting;
static unsigned long next_restart = 0;

static WiFiUDP WifiUdp;
static std::unique_ptr<NTPClient> ntpClient;

static char gtext_buffer[512];

void RunStateMachine(unsigned long millis) {
    if (ntpClient) {
        ntpClient->update();
        setTime(ntpClient->getEpochTime());
    }
    switch (current_state) {
        case State_Waiting:
            if (millis > next_restart) {
                current_state = State_ConnectToWifi;
                WiFi.mode(WIFI_STA);
                WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
            }
            break;
        case State_ConnectToWifi:
            Serial.printf("Wifi status: %d\n", WiFi.status());
            if (WiFi.isConnected()) {
                current_state = State_WifiConnected;
                if (!ntpClient) {
                    ntpClient = std::unique_ptr<NTPClient>(new NTPClient(WifiUdp, "au.pool.ntp.org", 10*3600, 60*60*1000));
                }

            } else if (WiFi.status() > WL_CONNECTED) {
                // error, retry
                current_state = State_Waiting;
            }
            break;
        case State_WifiConnected:
        {
            ntpClient->begin();
            ntpClient->forceUpdate();
            auto vals = ReloadHebCal(now());
            if (vals.error == 0) {              
              sprintf(gtext_buffer, "%d", vals.DayOfOmer);
              lv_label_set_text(ui_omerCounter, gtext_buffer);
              sprintf(gtext_buffer, "%s count", vals.isNighttime ? "Tonight" : "Today (before nightfall)");
              lv_label_set_text(ui_omerLabel, gtext_buffer);
              

              sprintf(gtext_buffer, "%s\n\n\n(updated: %d-%02d-%02d, %02d:%02d)", vals.hDate.c_str(), year(), month(), day(), hour(), minute());
              lv_textarea_set_text(ui_TextArea1, gtext_buffer);
              next_restart = millis + 1000 * vals.next_update_secs;
            } else {
                next_restart = millis + 60 * 1000 * 5; // 5min
            }
            Serial.printf("next update in %ldsecs\n", (next_restart-millis)/1000);
            ntpClient->end();
            WiFi.disconnect();
            current_state = State_Waiting;
        }
        break;
    };
}
