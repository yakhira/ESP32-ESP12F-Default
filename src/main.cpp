#include "setup/wifi.h"

// -------- DEFAULT SKETCH PARAMETERS --------
const int SKETCH_VERSION = 1; 

ESPWiFi espwifi("ESP32-D0WDQ5");

void setup() {
	espwifi.wifiConnect();
	if (WiFi.getMode() == WIFI_STA) {
		espwifi.updateSketch(SKETCH_VERSION);
	}
}

void loop() {
	if (WiFi.getMode() == WIFI_STA) {
		if (WiFi.status() != WL_CONNECTED) {
			WiFi.reconnect();
		}
	}

	espwifi.stateCheck();
}