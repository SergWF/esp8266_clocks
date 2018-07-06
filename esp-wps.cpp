#include <Arduino.h>
#include "config.h"

void showFiles(){
	String str = "";
	Dir dir = SPIFFS.openDir("/");
	while (dir.next()) {
		Serial.printf("file %s %d\r\n", dir.fileName().c_str(), dir.fileSize());
	    ;
	}
}


void setup() {
  Serial.begin(115200);
  Serial.println("START");
  SPIFFS.begin();

  delay(3000);
  Serial.println("=====before======");
  showFiles();
  Serial.println("=====end======");

  delay(1000);
  if(!loadConfig()){
	  Serial.println("Config not loaded");
  } else {
	  Serial.println("Config was loaded properly");
  }

}

void loop() {
	delay(1000);
	Serial.printf("loop: ssid=%s, password=%s\r\n", config.ssid, config.password);
}
