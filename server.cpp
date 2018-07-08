#include "server.h"

ESP8266WebServer server(80);

String rootHtmlTemplate =
		"<html> \
<head> \
<meta http-equiv='refresh' content='10'/> \
<title>ESP8266 WiFi Network</title> \
<style> \
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; font-size: 1.5em; Color: #000000; } \
h1 { Color: #AA0000; } \
</style> \
</head> \
<body> \
<h1>ESP8266 Wi-Fi Access Point and Web Server Demo</h1> \
'Go to <a href='setup'>configure page</a> to change values. <p>\
'Go to <a href='config'>see actual config</a> to change values. \
</body> \
</html>";

String setupHtmlTemplate =
		"<html> \
<head> \
<meta http-equiv='refresh' content='10'/> \
    <title>ESP8266 WiFi Network</title> \
    <style> \
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; font-size: 1.5em; Color: #000000; } \
      h1 { Color: #AA0000; } \
    </style> \
    </head> \
<body> \
	<h1>ESP8266 Configuration</h1> \
    <form action=\"save\" method=\"get\"> \
    	<div><label>SSID:</label><input type = \"text\" id=\"ssid\" name=\"ssid\"/></div> \
    	<div><label>PASSWORD:</label><input type = \"text\" id=\"password\" name=\"password\"/></div> \
    	<div><label>NTP SERVER:</label><input type = \"text\" id=\"ntp_server\" name=\"ntp_server\"/></div> \
    	<div> \
    	<input type=\"submit\" value=\"Save and restart\"> \
        <input type=\"reset\" value=\"Reset\"> \
        </div> \
    </form> \
</body> \
</html>";

void handleRoot() {
	server.send(200, "text/html", rootHtmlTemplate);
}

void handleSetup() {
	server.send(200, "text/html", setupHtmlTemplate);
}
void handleConfig() {
	server.send(200, "application/json", loadConfigString());
}

void handleSave() {
	Serial.println("SAVE");
	server.send(200, "text/html", loadConfigString());
}

void createWiFiAP() {

}

void startServer() {
	Serial.printf("IP address: [%s]", WiFi.localIP().toString().c_str());
	server.on("/", handleRoot);
	server.on("/setup", handleSetup);
	server.on("/config", handleConfig);
	server.on("/save", handleSave);
	server.begin();
}

void processServer() {
	server.handleClient();
}
