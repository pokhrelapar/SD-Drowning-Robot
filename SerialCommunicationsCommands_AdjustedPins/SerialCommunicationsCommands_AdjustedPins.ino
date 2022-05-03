#include <Servo.h>
#define ON LOW
#define OFF HIGH

// These are the pin numbers associated to the labeled valves
#define VALVE_1 44
#define VALVE_2 42
#define VALVE_3 40
#define VALVE_4 38
#define VALVE_5 36
#define VALVE_6 34
#define VALVE_7 32
#define VALVE_8 30
#define VALVE_9 26
#define VALVE_10 28
#define VALVE_11 24
#define VALVE_12 22
#define VALVE_13 50
#define VALVE_14 52
#define VALVE_15 46
#define VALVE_16 48

int LED = 13;
int state = 0;
int leftThrusterPin = 6;
int leftThrusterPowerPin = 3;
Servo leftServo;
int rightThrusterPin = 7;
int rightThrusterPowerPin = 4;
Servo rightServo;

int dumbServoPoopyPin = 12;
Server dumbServoPoopy;

int pumpPin = 2;

int reserved_relay = 5

int forwardSignal = 1700;
int backwardSignal = 1300;
int leftSignal = 2000;
int rightSignal = 2000;
int offLeftThrusterSignal = 1500; // appropriate turn off signal
int offRightThrusterSignal = 1490; // right thruster is turning off with this signal instead of 1500

int ballast1ValveWaterEntry = VALVE_3;
int ballast1ValveWaterExit = VALVE_1;
int ballast1ValveCO2Entry = VALVE_7;
int ballast1ValveCO2Exit = VALVE_13;

int ballast2ValveWaterEntry = VALVE_4;
int ballast2ValveWaterExit = VALVE_2;
int ballast2ValveCO2Entry = VALVE_8;
int ballast2ValveCO2Exit = VALVE_14;

int ballast3ValveWaterEntry = VALVE_5;
int ballast3ValveWaterExit = VALVE_11;
int ballast3ValveCO2Entry = VALVE_9;
int ballast3ValveCO2Exit = VALVE_15;

int ballast4ValveWaterEntry = VALVE_6;
int ballast4ValveWaterExit = VALVE_12;
int ballast4ValveCO2Entry = VALVE_10;
int ballast4ValveCO2Exit = VALVE_16;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(leftThrusterPowerPin, ON);
  digitalWrite(rightThrusterPowerPin, ON);
  
  leftServo.attach(leftThrusterPin);
  leftServo.writeMicroseconds(offLeftSignal);
  rightServo.attach(rightThrusterPin);
  rightServo.writeMicroseconds(offLeftSignal); // should be the same signal as the left thruster off signal

  dumbServoPoopy.attach(dumbServoPoopyPin);
}

void startMove(char dir) {
  switch(dir) {
    case 0x00:
      // forward
      //Serial.println("Start moving forward");
      leftServo.writeMicroseconds(forwardSignal);
      rightServo.writeMicroseconds(forwardSignal);
      break;
    case 0x01:
      // backward
      //Serial.println("Start moving backward");
      leftServo.writeMicroseconds(backwardSignal);
      rightServo.writeMicroseconds(backwardSignal);
      break;
    case 0x02:
      // left // turn on right thruster to turn left
      //Serial.println("Start moving left");
      rightServo.writeMicroseconds(leftSignal);
      break;
    case 0x03:
      // right // turn on left thruster to turn right
      //Serial.println("Start moving right");
      leftServo.writeMicroseconds(rightSignal);
      break;
    default:
      break;
  }
}

void stopMove(char dir) {
  switch(dir) {
    case 0x00:
      // forward
      //Serial.println("Stop moving forward");
      leftServo.writeMicroseconds(offLeftSignal);
      rightServo.writeMicroseconds(offRightSignal);
      break;
    case 0x01:
      // backward
      //Serial.println("Stop moving backward");
      leftServo.writeMicroseconds(offLeftSignal);
      rightServo.writeMicroseconds(offRightSignal);
      break;
    case 0x02:
      // left
      //Serial.println("Stop moving left");
      rightServo.writeMicroseconds(offRightSignal);
      break;
    case 0x03:
      // right
      //Serial.println("Stop moving right");
      leftServo.writeMicroseconds(offLeftSignal);
      break;
    default:
      break;
  }
}

// LOW = On High = OFF
void fill(char data) {
  switch(data) {
    case 0x00:
      // a + false
      Serial.println("Emptying tank a"); // fill with air
      digitalWrite(ballast1CO2Entry, ON);
      digitalWrite(ballast1WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x01:
      // a + true
      Serial.println("Filling tank a"); // fill with water
      digitalWrite(pumpPin, ON);
      digitalWrite(ballast1WaterEntry, ON);
      digitalWrite(ballast1CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x02:
      // b + false
      Serial.println("Emptying tank b");
      digitalWrite(ballast2CO2Entry, ON);
      digitalWrite(ballast2WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x03:
      // b + true
      Serial.println("Filling tank b");
      digitalWrite(pumpPin, ON);
      digitalWrite(ballast2WaterEntry, ON);
      digitalWrite(ballast2CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x04:
      // c + false
      Serial.println("Emptying tank c");
      digitalWrite(ballast3CO2Entry, ON);
      digitalWrite(ballast3WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x05:
      // c + true
      Serial.println("Filling tank c");
      digitalWrite(pumpPin, ON);
      digitalWrite(ballast3WaterEntry, ON);
      digitalWrite(ballast3CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x06:
      // d + false
      Serial.println("Emptying tank d");
      digitalWrite(ballast4CO2Entry, ON);
      digitalWrite(ballast4WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x07:
      // d + true
      Serial.println("Filling tank d");
      digitalWrite(pumpPin, ON);
      digitalWrite(ballast3WaterEntry, ON);
      digitalWrite(ballast3CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x08:
      // ab + false
      Serial.println("Emptying tank ab");
      //a
      digitalWrite(ballast1CO2Entry, ON);
      digitalWrite(ballast1WaterExit, ON);
      //b
      digitalWrite(ballast2CO2Entry, ON);
      digitalWrite(ballast2WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x09:
      // ab + true
      Serial.println("Filling tank ab");
      digitalWrite(pumpPin, ON);
      //a
      digitalWrite(ballast1WaterEntry, ON);
      digitalWrite(ballast1CO2Exit, ON);
      //b
      digitalWrite(ballast2WaterEntry, ON);
      digitalWrite(ballast2CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x0A:
      // cd + false
      Serial.println("Emptying tank cd");
      //c
      digitalWrite(ballast3CO2Entry, ON);
      digitalWrite(ballast3WaterExit, ON);
      //d
      digitalWrite(ballast4CO2Entry, ON);
      digitalWrite(ballast4WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x0B:
      // cd + true
      Serial.println("Filling tank cd");
      digitalWrite(pumpPin, ON);
      //c
      digitalWrite(ballast3WaterEntry, ON);
      digitalWrite(ballast3CO2Exit, ON);
      //d
      digitalWrite(ballast4WaterEntry, ON);
      digitalWrite(ballast4CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x0C:
      // all + false
      Serial.println("Emptying tank all");
      //a
      digitalWrite(ballast1CO2Entry, ON);
      digitalWrite(ballast1WaterExit, ON);
      //b
      digitalWrite(ballast2CO2Entry, ON);
      digitalWrite(ballast2WaterExit, ON);
      //c
      digitalWrite(ballast3CO2Entry, ON);
      digitalWrite(ballast3WaterExit, ON);
      //d
      digitalWrite(ballast4CO2Entry, ON);
      digitalWrite(ballast4WaterExit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x0D:
      // all + true
      Serial.println("Filling tank all");
      digitalWrite(pumpPin, ON);
      //a
      digitalWrite(ballast1WaterEntry, ON);
      digitalWrite(ballast1CO2Exit, ON);
      //b
      digitalWrite(ballast2WaterEntry, ON);
      digitalWrite(ballast2CO2Exit, ON);
       //c
      digitalWrite(ballast3WaterEntry, ON);
      digitalWrite(ballast3CO2Exit, ON);
      //d
      digitalWrite(ballast4WaterEntry, ON);
      digitalWrite(ballast4CO2Exit, ON);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    default:
      break;
  }
}

void stopFill(char data) {
  switch(data) {
    case 0x00:
      // a + false
      Serial.println("Stop emptying tank a");
      digitalWrite(ballast1CO2Entry, OFF);
      digitalWrite(ballast1WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x01:
      // a + true
      Serial.println("Stop filling tank a");
      digitalWrite(pumpPin, OFF);
      digitalWrite(ballast1WaterEntry, OFF);
      digitalWrite(ballast1CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x02:
      // b + false
      Serial.println("Stop emptying tank b");
      digitalWrite(ballast2CO2Entry, OFF);
      digitalWrite(ballast2WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x03:
      // b + true
      Serial.println("Stop filling tank b");
      digitalWrite(pumpPin, OFF);
      digitalWrite(ballast2WaterEntry, OFF);
      digitalWrite(ballast2CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x04:
      // c + false
      Serial.println("Stop emptying tank c");
      digitalWrite(ballast3CO2Entry, OFF);
      digitalWrite(ballast3WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x05:
      // c + true
      Serial.println("Stop filling tank c");
      digitalWrite(pumpPin, OFF);
      digitalWrite(ballast3WaterEntry, OFF);
      digitalWrite(ballast3CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x06:
      // d + false
      Serial.println("Stop emptying tank d");
      digitalWrite(ballast4CO2Entry, OFF);
      digitalWrite(ballast4WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x07:
      // d + true
      Serial.println("Stop filling tank d");
      digitalWrite(pumpPin, OFF);
      digitalWrite(ballast4WaterEntry, OFF);
      digitalWrite(ballast4CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x08:
      // ab + false
      Serial.println("Stop emptying tank ab");
      //a
      digitalWrite(ballast1CO2Entry, OFF);
      digitalWrite(ballast1WaterExit, OFF);
      //b
      digitalWrite(ballast2CO2Entry, OFF);
      digitalWrite(ballast2WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x09:
      // ab + true
      Serial.println("Stop filling tank ab");
      digitalWrite(pumpPin, OFF);
      //a
      digitalWrite(ballast1WaterEntry, OFF);
      digitalWrite(ballast1CO2Exit, OFF);
      //b
      digitalWrite(ballast2WaterEntry, OFF);
      digitalWrite(ballast2CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x0A:
      // cd + false
      Serial.println("Stop emptying tank cd");
      //c
      digitalWrite(ballast3CO2Entry, OFF);
      digitalWrite(ballast3WaterExit, OFF);
      //d
      digitalWrite(ballast4CO2Entry, OFF);
      digitalWrite(ballast4WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x0B:
      // cd + true
      Serial.println("Stop filling tank cd");
      digitalWrite(pumpPin, OFF);
      //c
      digitalWrite(ballast3WaterEntry, OFF);
      digitalWrite(ballast3CO2Exit, OFF);
      //d
      digitalWrite(ballast4WaterEntry, OFF);
      digitalWrite(ballast4CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x0C:
      // all + false
      Serial.println("Stop emptying tank all");
      //a
      digitalWrite(ballast1CO2Entry, OFF);
      digitalWrite(ballast1WaterExit, OFF);
      //b
      digitalWrite(ballast2CO2Entry, OFF);
      digitalWrite(ballast2WaterExit, OFF);
      //c
      digitalWrite(ballast3CO2Entry, OFF);
      digitalWrite(ballast3WaterExit, OFF);
      //d
      digitalWrite(ballast4CO2Entry, OFF);
      digitalWrite(ballast4WaterExit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 0x0D:
      // all + true
      Serial.println("Stop filling tank all");
      digitalWrite(pumpPin, OFF);
      //a
      digitalWrite(ballast1WaterEntry, OFF);
      digitalWrite(ballast1CO2Exit, OFF);
      //b
      digitalWrite(ballast2WaterEntry, OFF);
      digitalWrite(ballast2CO2Exit, OFF);
      //c
      digitalWrite(ballast3WaterEntry, OFF);
      digitalWrite(ballast3CO2Exit, OFF);
      //d
      digitalWrite(ballast4WaterEntry, OFF);
      digitalWrite(ballast4CO2Exit, OFF);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    default:
      break;
  }
}

void spokes(char state) {
  if(state) {
    Serial.println("Close spokes");
    
    for(int pos = 0;pos <= 180; pos++) {
      dumbServoPoopy.write(pos);
      delay(15);
    }
  } else {
    Serial.println("Open spokes");
  }
}

void changeLED(int state) {
  if(state) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}

void handleCommand(char action, char data) {
  switch(action) {
    case 0x10:
      // Start
      startMove(data);
      break;
    case 0x20:
      // Stop
      stopMove(data);
      break;
    case 0x30:
      // Fill
      fill(data);
      break;
    case 0x40:
      // StopFill
      stopFill(data);
      break;
    case 0x50:
      // Spokes
      spokes(data);
      break;
    default:
      break;
  } //*/
}

void loop() {
  // put your main code here, to run repeatedly:
  String command_string = Serial.readStringUntil('\r');
  char command = command_string[0];
  char action = command & 0xF0;
  char data = command & 0x0F;
  
  if(command_string != NULL) {
    state = !state;
    changeLED(state);
    handleCommand(action, data);
  }
}
