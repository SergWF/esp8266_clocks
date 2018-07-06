#include <Arduino.h>
#include "config.h"
#include "server.h"
#include "wps.h"
#include "activity.h"

#define MODE_UNKNOWN 0
#define MODE_SERVER_AP 1
#define MODE_WPS 2
#define MODE_ACTIVE 10

int mode = 0;

void setup() {
	Serial.begin(115200);
	Serial.println("START");
	SPIFFS.begin();

	delay(3000);

	if (!loadConfig()) {
		Serial.println("Config not loaded");
		mode = MODE_SERVER_AP;
	} else {
		Serial.println("Config was loaded properly");
		mode = MODE_ACTIVE;
	}
	switch (mode) {
	case MODE_SERVER_AP:
		startServer();
		break;
	case MODE_WPS:
		connectWPS();
		break;
	case MODE_ACTIVE:
		init();
		break;
	default:
		break;
	}
}

void loop() {
	delay(1000);
	switch (mode) {
		case MODE_SERVER_AP:
			processServer();
			break;
		case MODE_ACTIVE:
			processMainActivity();
			break;
		default:
			break;
		}
}
