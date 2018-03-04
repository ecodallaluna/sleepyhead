/*                                                 
 * ,---.|                        |   |              |
 * `---.|    ,---.,---.,---.,   .|---|,---.,---.,---|
 *     ||    |---'|---'|   ||   ||   ||---',---||   |
 * `---'`---'`---'`---'|---'`---|`   '`---'`---^`---'
 *                    |    `---'                    
 *  An interface that improves babies' most precious time
 * 
 *
 * Aalto University - School of Science
 * ME-E4200 Experimental User Interfaces - Spring 2016
 * 
 * 
 * Group Members
 *   Antti Alho
 *   Álvaro Mompó Camarasa
 *   Lingying Jiang
 *   Zhengwu Lu
 *   Ilario Toniello
 *   
 *   Arduino code vers. 0.2
 *   
 *   NOTES version 0.2:
 *   wifi integrated
 *   improved colors
 *   
 */


//libraries
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "ESP8266.h"
#include <SoftwareSerial.h>

// wifi parameters
SoftwareSerial mySerial(3,2); //RX,TX
#define SSID        "User-interface"
#define PASSWORD    "12345678"

ESP8266 wifi(mySerial);


//DHT sensor variables
#define DHTPIN            4         // Pin which is connected to the DHT sensor.
// Uncomment the type of sensor in use:
#define DHTTYPE           DHT11     // DHT 11 
//#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)
// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

//variables for RGB
int RGB[3];
int redLed = 11; // red LED in Digital Pin 11 (PWM)
int greenLed = 10; // green LED in Digital Pin 10 (PWM)
int blueLed = 9; // blue LED in Digital Pin 9 (PWM)

//variable for water pump
int pump = 12; // port to transistor that switch on the water pump

void setup() {
  Serial.begin(9600); 
  // Initialize device.
  Serial.print("setup begin\r\n");

  
//wifi setup
Serial.print("FW Version:");
    Serial.println(wifi.getVersion().c_str());
      
    if (wifi.setOprToStationSoftAP()) {
        Serial.print("to station + softap ok\r\n");
    } else {
        Serial.print("to station + softap err\r\n");
    }
 
    if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.print("Join AP success\r\n");
        Serial.print("IP: ");
        Serial.println(wifi.getLocalIP().c_str());    
    } else {
        Serial.print("Join AP failure\r\n");
    }
    
    if (wifi.enableMUX()) {
        Serial.print("multiple ok\r\n");
    } else {
        Serial.print("multiple err\r\n");
    }
    
    if (wifi.startTCPServer(8234)) {
        Serial.print("start tcp server ok\r\n");
    } else {
        Serial.print("start tcp server err\r\n");
    }
    
    if (wifi.setTCPServerTimeout(10)) { 
        Serial.print("set tcp server timout 10 seconds\r\n");
    } else {
        Serial.print("set tcp server timout err\r\n");
    }
    
    Serial.print("setup end\r\n");


  /*
  // sensor setup
  dht.begin();
  Serial.println("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
  */

//setup RGB output
  pinMode(redLed,OUTPUT); 
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT); 
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(blueLed,LOW);

//setup water pump output
  pinMode(pump,OUTPUT);
  digitalWrite(pump,LOW); 
  
}




void loop() {

// receive  humidity data from wifi

 Serial.begin(9600);
    Serial.print("setup begin\r\n");
    
    Serial.print("FW Version:");
    Serial.println(wifi.getVersion().c_str());
      
    if (wifi.setOprToStationSoftAP()) {
        Serial.print("to station + softap ok\r\n");
    } else {
        Serial.print("to station + softap err\r\n");
    }
 
    if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.print("Join AP success\r\n");
        Serial.print("IP: ");
        Serial.println(wifi.getLocalIP().c_str());    
    } else {
        Serial.print("Join AP failure\r\n");
    }
    
    if (wifi.enableMUX()) {
        Serial.print("multiple ok\r\n");
    } else {
        Serial.print("multiple err\r\n");
    }
    
    if (wifi.startTCPServer(8234)) {
        Serial.print("start tcp server ok\r\n");
    } else {
        Serial.print("start tcp server err\r\n");
    }
    
    if (wifi.setTCPServerTimeout(10)) { 
        Serial.print("set tcp server timout 10 seconds\r\n");
    } else {
        Serial.print("set tcp server timout err\r\n");
    }
    
    Serial.print("setup end\r\n");
}
 
void loop(void)
{
    uint8_t buffer[128] = {0};
    //uint8_t mux_id;
    
   while(1)
  {
    uint32_t len = wifi.recv(buffer, sizeof(buffer), 100);
    if (len > 0) {
        Serial.print("Status:[");
        Serial.print(wifi.getIPStatus().c_str());
        Serial.println("]");
        
//        Serial.print("Received from :");
//        Serial.print(mux_id);
          Serial.print(" ");
        for(uint32_t i = 0; i < len; i++) {
            Serial.print((char)buffer[i]);
        }
        Serial.print("\r\n");
      }
    }
//        if(wifi.send(mux_id, buffer, len)) {
//            Serial.print("send back ok\r\n");
//        } else {
//            Serial.print("send back err\r\n");
//        }
//        
//        if (wifi.releaseTCP(mux_id)) {
//            Serial.print("release tcp ");
//            Serial.print(mux_id);
//            Serial.println(" ok");
//        } else {
//            Serial.print("release tcp");
//            Serial.print(mux_id);
//            Serial.println(" err");
//        }
        
        Serial.print("Status:[");
        Serial.print(wifi.getIPStatus().c_str());
        Serial.println("]");



  /*
 // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
  */

  switchRGBOn(event.relative_humidity);
  waterPump(event.relative_humidity);

  
    
}
