#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Metodo para poder conectarse
class conectarweb{
  private:

  public:
    conectarweb(const char *_SSID, const char* _PASSWORD ){
      WiFi.begin(_SSID, _PASSWORD);
      while(WiFi.status()!= WL_CONNECTED){
          delay(500);
          Serial.print("...");
      }
    }

}; 

class DateTime
{
private:
  int defaultTime;
  struct tm timeinfo;
  const char *ntpServer = "pool.ntp.org";
  const long gmtOffset_sec = 0;
  const int daylightOffset_sec = 0;

public:
  char timeStringBuff[20];
  DateTime()
  {
    defaultTime = 0;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    getTime();
  }

  void getTime()
  {   
    setLocalTime();
  }
// metodo para conseguir la fecha
  void setLocalTime()
  {
    
    if (!getLocalTime(&timeinfo))
    {
    }
    strftime(timeStringBuff, sizeof(timeStringBuff), "%Y-%m-%dT%H:%M:%SZ", &timeinfo);
  }
};
conectarweb *webInterface;
DateTime *reloj;
StaticJsonDocument<512> horaActual;


const char *ssid="INFINITUM268A_2.4";
const char *passwrd="mCpp3x9Kpq";


void setup() {
  Serial.begin(115200);
  webInterface= new conectarweb(ssid,passwrd);
  reloj=new DateTime();
  
}
int suma=0;
void loop() {
  suma++;
  horaActual.clear();
  reloj->getTime();
  horaActual["hora"]=reloj->timeStringBuff;
  horaActual["Sumatoria"]=suma;
  serializeJson(horaActual,Serial);
  Serial.println("");
  delay(1000);
}

