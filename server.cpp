#include "server.h"


#define AP_SSID "wf-esp8266"
#define AP_PASSWORD "12345"

ESP8266WebServer server(80);
char html[1000];

String htmlTemplate = "<html>\
		  <head>\
		    <meta http-equiv='refresh' content='10'/>\
		    <title>Configuration</title>\
		    <style>\
		      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; font-size: 1.5em; Color: #000000; }\
		      h1 { Color: #AA0000; }\
		    </style>\
		  </head>\
		  <body>\
		 <form ></form>"
		""
		""
		"<h1>ESP8266 Wi-Fi Access Point and Web Server Demo</h1>\
		    <p>Uptime: %02d:%02d:%02d</p>\
		    <p>Brightness: %d%</p>\
		    <p>%s<p>\
		    <p>This page refreshes every 10 seconds. Click <a href=\"javascript:window.location.reload();\">here</a> to refresh the page now.</p>\
		  </body>\
		</html>";


void handleRoot(){

}

void handleConfig(){

}

void startServer(){
	WiFi.softAP(AP_SSID, AP_PASSWORD);
	server.on("/", handleRoot);
	server.on("/config", handleConfig);
}

void processServer(){
	server.handleClient();
}
