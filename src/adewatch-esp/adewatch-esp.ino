#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>        //ESP8266自带库，无需安装
#include <ESP8266_Seniverse.h>  //https://github.com/taichi-maker/ESP8266-Seniverse
//#include <WiFi.h>
static WiFiClient espClient;

#define NTP_OFFSET 60 * 60 * 8  // In seconds
#define NTP_INTERVAL 60 * 1000  // In miliseconds
#define NTP_ADDRESS "europe.pool.ntp.org"//随便写pool.ntp.org都行
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);
// 引入阿里云 IoT SDK
#include <AliyunIoTSDK.h>

// 设置产品和设备的信息，从阿里云设备信息里查看
#define PRODUCT_KEY "  "
#define DEVICE_NAME ""
#define DEVICE_SECRET ""
#define REGION_ID ""

const char* reqUserKey = "";  // 私钥
char* reqLocation = "";                 // 城市，可使用"ip"自动识别请求 IP 地址

const char* reqUnit = "c";  // 摄氏(c)/华氏(f)
#include <ArduinoJson.h>
WeatherNow weatherNow;  // 建立WeatherNow对象用于获取心知天气信息
void setup() {
  Serial.begin(19200);
  Serial.println("");
  WiFiManager wm;
  // wm.resetSettings(); //test wifi

  bool res;
  res = wm.autoConnect("FJR9476Y583U5UYYUYY'WIFI");  // 设置 ap
  if (!res) {
    Serial.println("Failed to connect");
    // ESP.restart();
  } else {
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
  }
  timeClient.begin();
  AliyunIoTSDK::begin(espClient, PRODUCT_KEY, DEVICE_NAME, DEVICE_SECRET, REGION_ID);

  //配置心知天气请求信息
  weatherNow.config(reqUserKey, reqLocation, reqUnit);
}


void loop() {
  //AliyunIoTSDK::loop();
  DynamicJsonDocument doc(1024);
  if (weatherNow.update()) {  // 更新天气信息
    doc["Type"] = reqLocation;
    doc["Temperature"] = weatherNow.getDegree();
    doc["weather"] = weatherNow.getWeatherText();
    timeClient.update();
    unsigned long epcohTime = timeClient.getEpochTime();
    // String formattedTime = timeClient.getFormattedTime();

    char buffer[50];
    sprintf(buffer, "%lu", epcohTime);
    String info = "T" + String(buffer);
    Serial.println();
    Serial.println(info);
    // Serial.println(formattedTime);

  } else {  // 更新失败
    Serial.println("Update Fail...");
    Serial.print("Server Response: ");           // 输出服务器响应状态码供用户查找问题
    Serial.println(weatherNow.getServerCode());  // 心知天气服务器错误代码说明可通过以下网址获取
  }
  AliyunIoTSDK::send((char*)"City", reqLocation);
  AliyunIoTSDK::send((char*)"CurrentTemp", weatherNow.getDegree());
  AliyunIoTSDK::send((char*)"Degree", weatherNow.getWeatherText());

  serializeJson(doc, Serial);
  delay(3000);
}
