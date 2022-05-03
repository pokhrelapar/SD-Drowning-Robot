#include <Servo.h>

// tank valves
int valves[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};
int num_valves = 16; 

// thrusters
int red_thruster_pin = 6;
int red_thruster_power = 3;
int yellow_thruster_pin = 7;
int yellow_thruster_power = 4;

Servo red_thruster;
Servo yellow_thruster;
Servo gate_hand_idk_what;

// servo
int servo_pin = 12;

// pump
int pump_power_pin = 2;

// reserved relay for whatever
int reserved_relay = 5;

void test_valves()
{
  for (int i = 0; i < num_valves; i++)
  {
    digitalWrite(valves[i], LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(valves[i], HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  }
  delay(2000);
}

void test_thrusters()
{
  // test red thruster
  digitalWrite(red_thruster_power, LOW);
  delay(3000);
  red_thruster.attach(red_thruster_pin);
  delay(3000);
  red_thruster.write(1500);
  delay(5000);
  red_thruster.writeMicroseconds(1700);
  delay(3000);
  red_thruster.writeMicroseconds(1500);
  delay(3000);
  digitalWrite(red_thruster_power, HIGH);

  // test yellow thruster
  digitalWrite(yellow_thruster_power, LOW);
  delay(3000);
  yellow_thruster.attach(yellow_thruster_pin);
  delay(3000);
  yellow_thruster.write(1500);
  delay(5000);
  yellow_thruster.writeMicroseconds(1700);
  delay(3000);
  yellow_thruster.writeMicroseconds(1490);
  delay(3000);
  digitalWrite(yellow_thruster_power, HIGH);

  delay(2000);
}

void test_servo()
{
  gate_hand_idk_what.attach(servo_pin);
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    gate_hand_idk_what.write(pos);   // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
}

void test_pump()
{
  digitalWrite(pump_power_pin, LOW);
  delay(2000);
  digitalWrite(pump_power_pin, HIGH);
  delay(2000);
}

void setup() {
  //signal LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // set all valves relays off
  for (int i = 0; i < num_valves; i++)
  {
    pinMode(valves[i], OUTPUT);
    digitalWrite(valves[i], HIGH);
  }

  // make sure both motors stays on
  pinMode(red_thruster_power, OUTPUT);
  pinMode(yellow_thruster_power, OUTPUT);
  digitalWrite(red_thruster_power, HIGH);
  digitalWrite(yellow_thruster_power, HIGH);

  // make sure pump motor stays off
  pinMode(pump_power_pin, OUTPUT);
  digitalWrite(pump_power_pin, HIGH);

  // wait for a bit
  delay(5000);

  // testing
  test_valves();
  test_thrusters(); /*
  for(int i = 0; i < 100; i++) {
    test_servo();
  }//*/
  test_servo();
  test_pump();

  // wait for a bit
  delay(2000);

  // all done, lights out
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

}
