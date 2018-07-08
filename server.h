#ifndef SERVER_H_
#define SERVER_H_

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include "config.h"

#define SERVER_START_MODE_AP 0
#define SERVER_START_MODE_WIFI 1

extern void startServer(int);
extern void processServer();

#endif /* SERVER_H_ */
