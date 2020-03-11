#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include <DHT.h>   
#include<ArduinoJson.h>

#define DHTTYPE DHT11   // Sensor DHT 11                                                         

#define FIREBASE_HOST "temperature-1e8f5.firebaseio.com"                          // database URL 
#define FIREBASE_AUTH "iXwilNNzhch9Rf69l7LM9Y9dg7RG9r9KMSgjBMDD"             // secret key

#define WIFI_SSID "ujjwal"                                           
#define WIFI_PASSWORD "ujjwal@123"                                    


#define dht_dpin D3
DHT dht(dht_dpin, DHTTYPE);      

void setup() {

  dht.begin();    
  Serial.begin(9600);

  Serial.println("Humidity and temperature \n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
                                                             //Start reading dht sensor
}

void loop() { 


  // Firebase Error Handling ************************************************
 if (Firebase.failed())
  { delay(500);
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Serial.println(Firebase.error());
  Serial.println("Ignoring firebase\n\n\n\n\n");
  delay(500);
  }

  else {
    Serial.println("Everything is ready!");
    delay(300); Serial.println("Everything is ready!");
    delay(300); Serial.println("Everything is ready!");
    delay(300);
  }


  
  float h = dht.readHumidity();                                              // Reading humidity
  float t = dht.readTemperature();                                           // Reading temperature
    
  if (isnan(h) || isnan(t)) {                                                // Check if any reads failed and exit early (to try again).
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    delay(2000);
    Firebase.setFloat("/temp",t);
}
  
