#include <Arduino.h>
#include "config.h"

#define CONFIG_WIFI_SSID_KEY "ssid"
#define CONFIG_WIFI_PASS_KEY "password"
#define CONFIG_FILE "config.json"

Config config;

bool loadConfig() {
	File configFile = SPIFFS.open(CONFIG_FILE, "r");
	StaticJsonBuffer<512> jsonBuffer;
	JsonObject &root = jsonBuffer.parseObject(configFile);
	if (!root.success()) {
		Serial.println(F("Failed to read file, using default configuration"));
		return false;
	}
	strlcpy(config.ssid, root[CONFIG_WIFI_SSID_KEY], sizeof(config.ssid));
	strlcpy(config.password, root[CONFIG_WIFI_PASS_KEY],
			sizeof(config.password));
	configFile.close();

	return true;
}

bool saveConfig() {
	SPIFFS.remove(CONFIG_FILE);
	File configFile = SPIFFS.open(CONFIG_FILE, "w");

	if(!configFile) {
		Serial.printf("Failed to open file [%s] for recording\r\n", CONFIG_FILE);
		return false;
	}
	StaticJsonBuffer<256> jsonBuffer;
	JsonObject &root = jsonBuffer.createObject();

	root[CONFIG_WIFI_SSID_KEY] = config.ssid;
	root[CONFIG_WIFI_PASS_KEY] = config.password;

	if (root.printTo(configFile) == 0) {
		Serial.println(F("Failed to write to file"));
	}
	configFile.close();
}
