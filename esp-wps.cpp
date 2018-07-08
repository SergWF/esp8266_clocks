#include <Arduino.h>
#include "config.h"
#include "server.h"
#include "wps.h"
#include "activity.h"

#define MODE_UNKNOWN 0
#define MODE_SETUP 1
#define MODE_ACTIVE 2
#define AP_SSID "wf-esp8266"
#define AP_PASSWORD "12345"
#define MAX_CONNECT_ATTEMPTS 60

int mode = MODE_UNKNOWN;

bool connectWifi();
void createAP();
void displayMode();

void setup() {
	Serial.begin(115200);
	Serial.println("START");
	SPIFFS.begin();
	delay(3000);

	//loadConfig();
//	if (connectWifi()) {
//		mode = MODE_ACTIVE;
//	} else {
//		mode = MODE_SETUP;
//		createAP();
//	}
//	displayMode();
}

void loop() {
//	processServer();
	if (mode == MODE_ACTIVE) {
		processMainActivity();
	}
}

///////////////////////////////////////////////////
bool connectWifi() {
	WiFi.begin(config.ssid, config.password); //Connect to the WiFi network
	int connect_attempts = 0;
	while (WiFi.status() != WL_CONNECTED) { //Wait for connection
		WiFi.hostname(config.hostname);
		delay(500);
		Serial.println("Waiting to connect…");
		if (connect_attempts > MAX_CONNECT_ATTEMPTS) {
			return false;
		}
	}
	Serial.printf("Connected to Wifi [%s]\r\n");
	Serial.printf("Please use http://%d for setup or http://%d/config for checking existing configuration\r\n", config.hostname, config.hostname);
	return true;
}

void createAP() {
	Serial.println("Starting AP....");
	WiFi.softAP(AP_SSID, AP_PASSWORD);
	String ap_ip = WiFi.softAPIP().toString();
	Serial.printf("Created AP %s with secret %s\r\n", AP_SSID, AP_PASSWORD);
	Serial.printf("Please use http://%d for setup or http://%d/config for checking existing configuration\r\n", ap_ip.c_str(), ap_ip.c_str());
}

void displayMode() {
	switch (mode) {
	case MODE_ACTIVE:
		Serial.println("mode=ACTIVE");
		break;
	case MODE_SETUP:
		Serial.println("mode=SETUP");
		break;
	default:
		Serial.println("mode=UNKNOWN");
		break;
	}

}
