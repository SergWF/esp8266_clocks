#ifndef CONFIG_H_
#define CONFIG_H_

#include <Arduino.h>
#include "libs/ArduinoJson.h"
#include <FS.h>

#define WIFI_SSID_MAX_LEN 40
#define WIFI_PASS_MAX_LEN 64
#define WIFI_HOST_MAX_LEN 64
#define NTP_LINK_MAX_LEN 256

typedef struct {
	char ssid[WIFI_SSID_MAX_LEN];
	char password[WIFI_PASS_MAX_LEN];
	char hostname[WIFI_HOST_MAX_LEN];
	char ntp_link[NTP_LINK_MAX_LEN];
} Config;

extern Config config;

extern bool loadConfig();
extern bool saveConfig();
extern String loadConfigString();


#endif /* CONFIG_H_ */
