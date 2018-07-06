#ifndef CONFIG_H_
#define CONFIG_H_

#include "libs/ArduinoJson.h"
#include <FS.h>

#define WIFI_SSID_MAX_LEN 40
#define WIFI_PASS_MAX_LEN 64

typedef struct {
	char ssid[WIFI_SSID_MAX_LEN];
	char password[WIFI_PASS_MAX_LEN];

} Config;

extern Config config;

extern bool loadConfig();
extern bool saveConfig();


#endif /* CONFIG_H_ */
