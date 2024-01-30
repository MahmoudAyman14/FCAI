#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncWebSocket.h>

#define MOTOR_RUN_TIME_fb 150      // Time to move forward in milliseconds
#define MOTOR_RUN_TIME_lr 300
#define left_delay 400
#define backward_delay 75
#include <NewPing.h>

bool flag = true;


#define FORWARD 1
#define BACKWARD 2
#define STOP 0
#define LEFT 3
#define RIGHT 4
#define UPLEFT 5
#define UPRIGHT 6


// Pin configuration for Motor 1
#define MOTOR1_HBRIDGE_PIN1 27  // Replace with the actual pin connected to IN1 of the H-bridge for Motor 1
#define MOTOR1_HBRIDGE_PIN2 14  // Replace with the actual pin connected to IN2 of the H-bridge for Motor 1

// Pin configuration for Motor 2
#define MOTOR2_HBRIDGE_PIN1 19  // Replace with the actual pin connected to IN1 of the H-bridge for Motor 2
#define MOTOR2_HBRIDGE_PIN2 18  // Replace with the actual pin connected to IN2 of the H-bridge for Motor 2

// Pin configuration for Motor 3
#define MOTOR3_HBRIDGE_PIN1 22  // Replace with the actual pin connected to IN1 of the H-bridge for Motor 3
#define MOTOR3_HBRIDGE_PIN2 23  // Replace with the actual pin connected to IN2 of the H-bridge for Motor 3

// Pin configuration for Motor 4
#define MOTOR4_HBRIDGE_PIN1 26  // Replace with the actual pin connected to IN1 of the H-bridge for Motor 4
#define MOTOR4_HBRIDGE_PIN2 25  // Replace with the actual pin connected to IN2 of the H-bridge for Motor 4




#define TRIG1 32
#define ECHO1 35
#define TRIG2 13
#define ECHO2 34
#define TRIG3 21
#define ECHO3 33













const char* ssid = "seifcar";
const char* password = "1234567##";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");



const char* htmlHomePage PROGMEM = R"HTMLHOMEPAGE(
<!DOCTYPE html>
<html>
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <style>
    .arrows {
      font-size:70px;
      color:red;
    }
    .circularArrows {
      font-size:80px;
      color:blue;
    }
    td {
      background-color:black;
      border-radius:25%;
      box-shadow: 5px 5px #888888;
    }
    td:active {
      transform: translate(5px,5px);
      box-shadow: none; 
    }

    .noselect {
      -webkit-touch-callout: none; /* iOS Safari */
        -webkit-user-select: none; /* Safari */
         -khtml-user-select: none; /* Konqueror HTML */
           -moz-user-select: none; /* Firefox */
            -ms-user-select: none; /* Internet Explorer/Edge */
                user-select: none; /* Non-prefixed version, currently
                                      supported by Chrome and Opera */
    }
    </style>
  </head>
  <body class="noselect" align="center" style="background-color:white">
     
    <h1 style="color: teal;text-align:center;">Hash Include Electronics</h1>
    <h2 style="color: teal;text-align:center;">Wi-Fi &#128663; Control</h2>
    
    <table id="mainTable" style="width:400px;margin:auto;table-layout:fixed" CELLSPACING=10>
      <tr>
        <td ontouchstart='onTouchStartAndEnd("5")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11017;</span></td>
        <td ontouchstart='onTouchStartAndEnd("1")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8679;</span></td> //Backward Button
        <td ontouchstart='onTouchStartAndEnd("6")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11016;</span></td>
      </tr>
      
      <tr>
        <td ontouchstart='onTouchStartAndEnd("3")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8678;</span></td>
        <td></td>    
        <td ontouchstart='onTouchStartAndEnd("4")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8680;</span></td>
      </tr>
      
      <tr>
        <td ontouchstart='onTouchStartAndEnd("7")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11019;</span></td> //back left
        <td ontouchstart='onTouchStartAndEnd("2")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#8681;</span></td> // Forward Button
        <td ontouchstart='onTouchStartAndEnd("0")' ontouchend='onTouchStartAndEnd("0")'><span class="arrows" >&#11018;</span></td>
      </tr>
    
      <tr>
        <td ontouchstart='onTouchStartAndEnd("9")' ontouchend='onTouchStartAndEnd("0")'><span class="circularArrows" >&#8634;</span></td>
        <td style="background-color:white;box-shadow:none"></td>
        <td ontouchstart='onTouchStartAndEnd("10")' ontouchend='onTouchStartAndEnd("0")'><span class="circularArrows" >&#8635;</span>auto</td>
      </tr>


    </table>

<script>
  var webSocketUrl = "ws:\/\/" + window.location.hostname + "/ws";
  var websocket;
  
  function initWebSocket() {
    websocket = new WebSocket(webSocketUrl);
    websocket.onopen = function(event) {};
    websocket.onclose = function(event) {
      setTimeout(initWebSocket, 2000);
    };
    websocket.onmessage = function(event) {};
  }

  function onTouchStartAndEnd(value) {
      websocket.send(value);
    }


  window.onload = initWebSocket;
  document.getElementById("mainTable").addEventListener("touchend", function(event) {
    event.preventDefault();
  });
</script>

  </body>
</html> 

)HTMLHOMEPAGE";



void rotateMotor1(int direction) {
  if (direction == BACKWARD) {
    digitalWrite(MOTOR1_HBRIDGE_PIN1, HIGH);
    digitalWrite(MOTOR1_HBRIDGE_PIN2, LOW);
  } else if (direction == FORWARD) {
    digitalWrite(MOTOR1_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR1_HBRIDGE_PIN2, HIGH);
  } else {
    digitalWrite(MOTOR1_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR1_HBRIDGE_PIN2, LOW);
  }
}

void rotateMotor2(int direction) {
  if (direction == BACKWARD) {
    digitalWrite(MOTOR2_HBRIDGE_PIN1, HIGH);
    digitalWrite(MOTOR2_HBRIDGE_PIN2, LOW);
  } else if (direction == FORWARD) {
    digitalWrite(MOTOR2_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR2_HBRIDGE_PIN2, HIGH);
  } else {
    digitalWrite(MOTOR2_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR2_HBRIDGE_PIN2, LOW);
  }
}

void rotateMotor3(int direction) {
  if (direction == BACKWARD) {
    digitalWrite(MOTOR3_HBRIDGE_PIN1, HIGH);
    digitalWrite(MOTOR3_HBRIDGE_PIN2, LOW);
  } else if (direction == FORWARD) {
    digitalWrite(MOTOR3_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR3_HBRIDGE_PIN2, HIGH);
  } else {
    digitalWrite(MOTOR3_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR3_HBRIDGE_PIN2, LOW);
  }
}

void rotateMotor4(int direction) {
  if (direction == BACKWARD) {
    digitalWrite(MOTOR4_HBRIDGE_PIN1, HIGH);
    digitalWrite(MOTOR4_HBRIDGE_PIN2, LOW);
  } else if (direction == FORWARD) {
    digitalWrite(MOTOR4_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR4_HBRIDGE_PIN2, HIGH);
  } else {
    digitalWrite(MOTOR4_HBRIDGE_PIN1, LOW);
    digitalWrite(MOTOR4_HBRIDGE_PIN2, LOW);
  }
}

void processCarMovement(String inputValue) {
  Serial.printf("Got value as %s %d\n", inputValue.c_str(), inputValue.toInt());

  switch (inputValue.toInt()) {
    case FORWARD:
      rotateMotor1(FORWARD);
      rotateMotor2(FORWARD);
      rotateMotor3(FORWARD);
      rotateMotor4(FORWARD);
      break;

    case BACKWARD:
      rotateMotor1(BACKWARD);
      rotateMotor2(BACKWARD);
      rotateMotor3(BACKWARD);
      rotateMotor4(BACKWARD);
      break;
    
    case LEFT:
      rotateMotor1(FORWARD);
      rotateMotor2(FORWARD);
      rotateMotor3(BACKWARD);
      rotateMotor4(BACKWARD);
      break;
    
    case RIGHT:
      rotateMotor1(BACKWARD);
      rotateMotor2(BACKWARD);
      rotateMotor3(FORWARD);
      rotateMotor4(FORWARD);
      break;

    case UPLEFT: 
      rotateMotor1(STOP);
      rotateMotor2(FORWARD);
      rotateMotor3(STOP);  
      rotateMotor4(BACKWARD);
      break;

    case UPRIGHT:
      rotateMotor1(STOP);
      rotateMotor2(BACKWARD);
      rotateMotor3(FORWARD);  
      rotateMotor4(STOP);
      break;      
  
    case STOP:
      rotateMotor1(STOP);
      rotateMotor2(STOP);
      rotateMotor3(STOP);
      rotateMotor4(STOP);
      break;

    default:
      rotateMotor1(STOP);
      rotateMotor2(STOP);
      rotateMotor3(STOP);
      rotateMotor4(STOP);
      break;
  }
}








#define TRIGGER_PIN_FORWARD 32  // Pin connected to the forward ultrasonic sensor's trigger
#define ECHO_PIN_FORWARD 35       // Pin connected to the forward ultrasonic sensor's echo
#define TRIGGER_PIN_RIGHT 13     // Pin connected to the right-side ultrasonic sensor's trigger
#define ECHO_PIN_RIGHT 34         // Pin connected to the right-side ultrasonic sensor's echo
#define TRIGGER_PIN_BACKWARD 21 
#define ECHO_PIN_BACKWARD 33

#define MAX_DISTANCE 200          // Maximum distance to measure in centimeters


// Function to measure distances for a single ultrasonic sensor
long measureDistance(int triggerPin, int echoPin) {
  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the time it takes for the pulse to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound (approx. 343 meters/second)
  long distance = duration * 0.0343 / 2;

  return distance;
}




// Function to measure distances for all three ultrasonic sensors
bool forwardmeasure() {
  // Measure distance from sensor 1
  long distance1 = measureDistance(TRIG1, ECHO1);
  //Serial.print("Distance Sensor 1: ");
  //Serial.print(distance1);
  //Serial.println(" cm");
  if(distance1>=10)
  {
    Serial.println(" valid....!");
    return true;
  

  }
  else{
    Serial.println("not  valid....!");
    return false;
  }
}
bool rightmeasure(){
  // Measure distance from sensor 2
  long distance2 = measureDistance(TRIG2, ECHO2);
  //Serial.print("Distance Sensor 2: ");
  //Serial.print(distance2);
  //Serial.println(" cm");
    if(distance2>=30)
  {
    return true;
  }
  else{
    return false;
  }
}

 bool backwardmeasure(){
  // Measure distance from sensor 3
  long distance3 = measureDistance(TRIG3, ECHO3);
  //Serial.print("Distance Sensor 3: ");
  //Serial.print(distance3);
  //Serial.println(" cm");
    if(distance3>=10)
  {
    return true;
  }
  else{
    return false;
  }
}





void moveforward() {
  while (rightmeasure() && !forwardmeasure ()) {
    processCarMovement("1"); // Move forward
    delay(MOTOR_RUN_TIME_fb); // Move for a fixed duration
    processCarMovement("0");
    delay(200); // Add a small delay for stability
  }
}

bool rightmeasurepark(){
  // Measure distance from sensor 2
  long distance4 = measureDistance(TRIG2, ECHO2);
  //Serial.print("Distance Sensor 2: ");
  //Serial.print(distance2);
  //Serial.println(" cm");
    if(distance4>=8)
  {
    return true;
  }
  else{
    return false;
  }
}
long distance4 = measureDistance(TRIG2, ECHO2);
void moveRightPark() {
  while (rightmeasurepark()) {
    Serial.println(distance4);
    processCarMovement("4"); // Move forward
    delay(backward_delay); // Move for a fixed duration
    processCarMovement("0");
    delay(1000);
  }
}    



void movebackward() {
  while (backwardmeasure()) {
    processCarMovement("2"); // Move backward
    delay(backward_delay); // Move for a fixed duration
    processCarMovement("0");
    delay(1000);
     // Add a small delay for stability
  }
}
    



void handleRoot(AsyncWebServerRequest* request) {
  request->send_P(200, "text/html", htmlHomePage);
}

void handleNotFound(AsyncWebServerRequest* request) {
  request->send(404, "text/plain", "File Not Found");
}

void onWebSocketEvent(AsyncWebSocket* server, AsyncWebSocketClient* client,
                      AwsEventType type, void* arg, uint8_t* data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(),
                    client->remoteIP().toString().c_str());
      break;

    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      processCarMovement("0");
      break;

    case WS_EVT_DATA:
      AwsFrameInfo* info;
      info = (AwsFrameInfo*)arg;
      if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        std::string myData = "";
        myData.assign((char*)data, len);
        processCarMovement(myData.c_str());
      }
      break;

    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;

    default:
      break;
  }
}

void setupPinModes() {
  pinMode(MOTOR1_HBRIDGE_PIN1, OUTPUT);
  pinMode(MOTOR1_HBRIDGE_PIN2, OUTPUT);
  pinMode(MOTOR2_HBRIDGE_PIN1, OUTPUT);
  pinMode(MOTOR2_HBRIDGE_PIN2, OUTPUT);
  pinMode(MOTOR3_HBRIDGE_PIN1, OUTPUT);
  pinMode(MOTOR3_HBRIDGE_PIN2, OUTPUT);
  pinMode(MOTOR4_HBRIDGE_PIN1, OUTPUT);
  pinMode(MOTOR4_HBRIDGE_PIN2, OUTPUT);

  rotateMotor1(STOP);
  rotateMotor2(STOP);
  rotateMotor3(STOP);
  rotateMotor4(STOP);
}

void setup() {

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
  setupPinModes();
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);

  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);

  server.begin();
  Serial.println("HTTP server started");
}

void autoPark() {
  Serial.println("Initiating auto-park sequence...");

  // Move forward
  processCarMovement("1");
  delay(MOTOR_RUN_TIME_fb);
    // Adjust the duration based on your needs
  processCarMovement("0");
  delay(1000);

  // Move UPLEFT
  processCarMovement("3");
  delay(left_delay);
    // Adjust the duration based on your needs
  processCarMovement("0");
  delay(1000);

  // Move backward
  movebackward();



  moveRightPark();

  // // Move UPRIGHT
  // processCarMovement("4");
  // delay(MOTOR_RUN_TIME_lr);
  //  // Adjust the duration based on your needs
  // processCarMovement("0");
  // delay(1000); 

  Serial.println("Auto-park sequence completed.");
  flag = false;

}


void loop() {
  
  if(forwardmeasure())
  {
    
  while (flag) {
    // Check if there is space on the right and in front
    if (rightmeasure() && forwardmeasure()) {
      Serial.println("Space found on the right and in front. Initiating parking...");
      autoPark();
      break;  // Exit the loop after parking
    } else {
      Serial.println("No space on the right or in front. Moving forward for 1 second...");
      processCarMovement("1");  // Move forward
      delay(MOTOR_RUN_TIME_fb);
      processCarMovement("0"); 
      delay(1000);  // Move forward for 1 second
 // Stop the car

      // Check if there is space on the right and in front after moving forward
      if (rightmeasure() && forwardmeasure()) {
        Serial.println("Space found on the right and in front. Initiating parking...");
        autoPark();
        break;  // Exit the loop after parking
      } else {
        Serial.println("No space on the right or in front. Continuing the search...");
        // Continue the loop to check for available spaces

      }
    }
    break;
  }
 
  }else
  {
    Serial.println("جري ايه يا حوده ");

}

}