#include <WiFi.h>
#include <math.h>

const char* ssid = "MobileRobot";
const char* password = "12345678";

struct Point {
  float x;
  float y;
};

struct StationaryRobot {
  const char* ssid;
  float distance;
  Point position;
} stationaryRobots[] = {
  {"Meshref", 0, {0, 100}},
  {"Ezz", 0, {100, 50}},
  {"miSeif", 0, {0, 0}}
};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}

void loop() {
  Serial.println("Scanning for stationary robots...");
  int n = WiFi.scanNetworks();
  
  for (int i = 0; i < n; ++i) {
    for (StationaryRobot& robot : stationaryRobots) {
      if (WiFi.SSID(i) == robot.ssid) {
        int rssi = WiFi.RSSI(i);
        robot.distance = rssiToDistance(rssi);
        Serial.printf("Distance to %s: %.2f cm\n", robot.ssid, robot.distance);
      }
    }
  }

  // Calculate the position of the mobile robot
  Point mobileRobotPosition = calculatePosition();
  Serial.printf("Mobile Robot Position: (%.2f, %.2f)\n", mobileRobotPosition.x, mobileRobotPosition.y);

  WiFi.softAP(ssid, password);
  delay(5000);
}

float rssiToDistance(int rssi) {
  const double A = -45;
  const double n = 2.0;
  float distance = pow(10.0, (A - rssi) / (10 * n));
  return distance;
}

Point calculatePosition() {
  // Using trilateration to find the position of the mobile robot
  Point p1 = stationaryRobots[0].position;
  Point p2 = stationaryRobots[1].position;
  Point p3 = stationaryRobots[2].position;
  float r1 = stationaryRobots[0].distance;
  float r2 = stationaryRobots[1].distance;
  float r3 = stationaryRobots[2].distance;

  float A = 2*p2.x - 2*p1.x;
  float B = 2*p2.y - 2*p1.y;
  float C = r1*r1 - r2*r2 - p1.x*p1.x - p1.y*p1.y + p2.x*p2.x + p2.y*p2.y;
  float D = 2*p3.x - 2*p2.x;
  float E = 2*p3.y - 2*p2.y;
  float F = r2*r2 - r3*r3 - p2.x*p2.x - p2.y*p2.y + p3.x*p3.x + p3.y*p3.y;

  float x = (C*E - F*B) / (E*A - B*D);
  float y = (C*D - A*F) / (B*D - A*E);

  return{x,y};
}