# esp8266_clocks

1. Checks if config.json exists.
1.1 If exists, loads configuration from the file
1.2 otherwise starts WPS connection //option 1 
1.2.1 In case of success, saves network credentials to config.json
1.3 otherwise it creates an access point with SSID="wf-esp8266" and password="12345" and config page by address http://192.168.4.1  //option 2
1.3.1 after receiving config data it saves to config.json and reboot a board  
2. Requests curent time from network
3. Displays time  

Requirements:

ESP8266 libraries: http://arduino.esp8266.com/stable/package_esp8266com_index.json
	ESP8266Wifi
	ESP8266WebServer

Library usage: 
	ArduinoJson: https://github.com/bblanchon/ArduinoJson
