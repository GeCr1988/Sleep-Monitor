#include <WiFi.h>
#include <HTTPClient.h>  // <-- This is required
#include "Secrets.h"

//https://mischianti.org/esp32-wemos-lolin32-lite-high-resolution-pinout-and-specs/
// Replace with your Wi-Fi credentials
const char* ssid = WIFI_SSID ;
const char* password = WIFI_PASSWORD;
// Server endpoint (Change this to your server API)
const char* serverURL = "http://192.168.68.101:5000/api/data";  // Replace with your PC's IP


void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected to Wi-Fi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());  // Print ESP32's local IP address
}

void loop() {
      // Read sensor data
    float temperature = 3.5;// dht.readTemperature();
    float humidity = 60;//dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C, Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    // Send data to HTTP Server
    sendToServer(temperature, humidity);

    // // Send data to Thingspeak
    // sendToThingspeak(temperature, humidity);

    delay(15000);   
    // Your code here
}

// Function to send data to a custom server
void sendToServer(float temperature, float humidity) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverURL);
        http.addHeader("Content-Type", "application/json");

        String jsonData = "{\"temperature\": " + String(temperature) +
                          ", \"humidity\": " + String(humidity) + "}";

        int httpResponseCode = http.POST(jsonData);

        if (httpResponseCode > 0) {
            Serial.print("Server Response: ");
            Serial.println(http.getString());
        } else {
            Serial.print("Error sending data: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    }
}

// // Function to send data to Thingspeak
// void sendToThingspeak(float temperature, float humidity) {
//     if (WiFi.status() == WL_CONNECTED) {
//         HTTPClient http;
//         String url = "http://api.thingspeak.com/update?api_key=" + String(thingspeakApiKey) +
//                      "&field1=" + String(temperature) + "&field2=" + String(humidity);

//         http.begin(url);
//         int httpResponseCode = http.GET();

//         if (httpResponseCode > 0) {
//             Serial.print("Thingspeak Response: ");
//             Serial.println(http.getString());
//         } else {
//             Serial.print("Error sending data: ");
//             Serial.println(httpResponseCode);
//         }

//         http.end();
//     }
// }
