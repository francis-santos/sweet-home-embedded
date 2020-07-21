#include <WiFi.h>
#include <WiFiUdp.h>
#include <ESPmDNS.h> //lib de comunição network

const char * SSID = "Keu&Fran";
const char * PASSWORD = "francis1986";

//ip estático, o mesmo deve ser usado no app do smartphone
IPAddress staticIP(192,168,0,120);
//gateway, deixe aqui o gateway da rede em que está conectado
IPAddress gateway(192,168,0,255);
//máscara, deixe aqui a máscara da rede em que está conectado
IPAddress subnet(255,255,255,0);

//objeto do servidor
WiFiServer server(80);

void initWifi() {
  WiFi.mode(WIFI_STA);

  WiFi.begin(SSID, PASSWORD);

  //configura os dados de rede
  WiFi.config(staticIP, gateway, subnet);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
}