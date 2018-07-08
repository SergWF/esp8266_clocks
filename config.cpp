#include "config.h"

#define CONFIG_WIFI_SSID_KEY "ssid"
#define CONFIG_WIFI_PASS_KEY "password"
#define CONFIG_WIFI_HOST_KEY "hostname"
#define CONFIG_NTP_LINK_KEY "ntp_link"
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
	strlcpy(config.hostname, root[CONFIG_WIFI_HOST_KEY], sizeof(config.hostname));
	strlcpy(config.ntp_link, root[CONFIG_NTP_LINK_KEY], sizeof(config.ntp_link));

	configFile.close();

	return true;
}

String loadConfigString() {
	File configFile = SPIFFS.open(CONFIG_FILE, "r");
	int fileSize = configFile.size();
	String content = configFile.readString();
	configFile.close();
	return content;
}

bool saveConfig() {
	SPIFFS.remove(CONFIG_FILE);
	File configFile = SPIFFS.open(CONFIG_FILE, "w");

	if (!configFile) {
		Serial.printf("Failed to open file [%s] for recording\r\n",
				CONFIG_FILE);
		return false;
	}
	StaticJsonBuffer<256> jsonBuffer;
	JsonObject &root = jsonBuffer.createObject();

	root[CONFIG_WIFI_SSID_KEY] = config.ssid;
	root[CONFIG_WIFI_PASS_KEY] = config.password;
	root[CONFIG_WIFI_HOST_KEY] = config.hostname;
	root[CONFIG_NTP_LINK_KEY] = config.ntp_link;

	if (root.printTo(configFile) == 0) {
		Serial.println(F("Failed to write to file"));
	}
	configFile.close();
	return true;
}
