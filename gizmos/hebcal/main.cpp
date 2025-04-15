#include <Arduino.h>
#include "secrets.h"

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include <WiFi.h>
#include "HTTPClient.h"
#include "ArduinoJson.h"

void initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());
}

struct HebcalVals {
  bool ShabbasMode;
  bool IsErevShabbasOrChag;
  String HebDate;
  int OmerCount;
};

int GetHebcalVals(HebcalVals& out) {
  HTTPClient http;
  http.setAuthorizationType("Bearer");
  http.setAuthorization(HA_API_KEY);
  http.begin("http://homeassistant.local:8123/api/states/sensor.hebcal_interesting_json");
  // Send HTTP GET request
  int httpResponseCode = http.GET();
    
  if (httpResponseCode == 200) {
    String payload = http.getString();
    http.end();
    JsonDocument jdoc;
    DeserializationError error;
    if ((error = deserializeJson(jdoc, payload))) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return -1;
    }
    String inner = jdoc["state"].as<String>();
    if ((error = deserializeJson(jdoc, inner))) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return -2;
    }
    out.ShabbasMode = jdoc["shabbas_mode"];
    out.IsErevShabbasOrChag = jdoc["erev_shabbat_hag"];
    out.HebDate = jdoc["heb_date"].as<String>();
    out.OmerCount = jdoc["omer"];
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  return 0;
}

void setup()
{
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();

    __attribute__((unused)) auto disp = lv_disp_get_default();
    // lv_disp_set_rotation(disp, LV_DISP_ROT_90);
    // lv_disp_set_rotation(disp, LV_DISP_ROT_180);
    // lv_disp_set_rotation(disp, LV_DISP_ROT_270);

    ui_init();
    initWiFi();
}

ulong next_millis;
auto lv_last_tick = millis();

void loop()
{
    auto const now = millis();
    if (now > next_millis)
    {
        next_millis = now + 500;

#ifdef BOARD_HAS_RGB_LED
        auto const rgb = (now / 2000) % 8;
        smartdisplay_led_set_rgb(rgb & 0x01, rgb & 0x02, rgb & 0x04);
#endif

#ifdef BOARD_HAS_CDS
        auto cdr = analogReadMilliVolts(CDS);
        sprintf(text_buffer, "%d", cdr);
        lv_label_set_text(ui_lblCdrValue, text_buffer);
#endif
    }

    // Update the ticker
    lv_tick_inc(now - lv_last_tick);
    lv_last_tick = now;
    // Update the UI
    lv_timer_handler();
    delay(10000);

    HebcalVals vals;
    if (GetHebcalVals(vals) == 0) {
      Serial.print(vals.HebDate);
      Serial.print(" ");
      Serial.print(vals.ShabbasMode);
      Serial.print(" ");
      Serial.print(vals.IsErevShabbasOrChag);
      Serial.print(" ");
      Serial.print(vals.OmerCount);
      Serial.print(" ");
      
      char text_buffer[32];
      sprintf(text_buffer, "%lu", vals.OmerCount);
      lv_label_set_text(ui_omernumber, text_buffer);
    }
}