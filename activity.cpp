#include "activity.h"

void initMainActivity(){
//	if(!connectWifi()) {
//		Serial.println("Can't connect Wifi Network.");
//	}
//	startServer(SERVER_START_MODE_WIFI);
}

void displayTime(long* timestamp){
	Serial.println();
}

long* getNtp(){
	return NULL;
}

void processMainActivity(){
	long* time = getNtp();
}
