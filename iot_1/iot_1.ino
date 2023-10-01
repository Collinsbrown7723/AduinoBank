#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define the webpage content
  server.on("/", HTTP_GET, handleRoot);

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String webpage = "<html><body>";
  webpage += "<h1>Welcome to ESP8266 Web Server</h1>";
  webpage += "<p>Connect to this device to send and receive data.</p>";
  webpage += "<form method='post' action='/send'>";
  webpage += "Data: <input type='text' name='data'><br>";
  webpage += "<input type='submit' value='Send Data'>";
  webpage += "</form>";
  webpage += "</body></html>";

  server.send(200, "text/html", webpage);
}

// Handle the POST request when data is sent
void handleData() {
  if (server.hasArg("data")) {
    String data = server.arg("data");
    // Process the received data as needed
    Serial.println("Received data: " + data);
    // You can perform actions with the received data here
    // For example, you can store it, control devices, etc.
  }

  // Redirect back to the root page
  server.sendHeader("Location", "/", true);
  server.send(303);
}
