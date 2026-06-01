#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "TPSN035";
const char* password = "BTSSN2022";
WebServer server(80);

void handlePost(){
  if(server.hasArg("plain")){
    String body=server.arg("plain");
    Serial.print(body);
    Serial2.println(body);
    server.send(200,"text/plain","OK");
  }else server.send(400,"text/plain","No data");
}

void setup(){
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED) delay(500);
  server.on("/json", HTTP_POST, handlePost);
  server.begin();
  Serial.println(WiFi.localIP());
}

void loop(){ server.handleClient(); }
