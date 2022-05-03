// valve pins
int ballast1ValveWaterEntry = 22;
int ballast1ValveWaterExit = 24;
int ballast1ValveCO2Entry = 26;
int ballast1ValveCO2Exit = 28;

int ballast2ValveWaterEntry = 30;
int ballast2ValveWaterExit = 32;
int ballast2ValveCO2Entry = 34;
int ballast2ValveCO2Exit = 36;

int ballast3ValveWaterEntry = 38;
int ballast3ValveWaterExit = 40;
int ballast3ValveCO2Entry = 42;
int ballast3ValveCO2Exit = 44;

int ballast4ValveWaterEntry = 46;
int ballast4ValveWaterExit = 48;
int ballast4ValveCO2Entry = 50;
int ballast4ValveCO2Exit = 52;

int waterPump = 23;
int thrusterLeft = 25;
int thrusterRight = 27;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ballast1ValveWaterEntry, OUTPUT);
  pinMode(ballast1ValveWaterExit, OUTPUT);
  pinMode(ballast1ValveCO2Entry, OUTPUT);
  pinMode(ballast1ValveCO2Exit, OUTPUT);

  pinMode(ballast2ValveWaterEntry, OUTPUT);
  pinMode(ballast2ValveWaterExit, OUTPUT);
  pinMode(ballast2ValveCO2Entry, OUTPUT);
  pinMode(ballast2ValveCO2Exit, OUTPUT);

  pinMode(ballast3ValveWaterEntry, OUTPUT);
  pinMode(ballast3ValveWaterExit, OUTPUT);
  pinMode(ballast3ValveCO2Entry, OUTPUT);
  pinMode(ballast3ValveCO2Exit, OUTPUT);

  pinMode(ballast4ValveWaterEntry, OUTPUT);
  pinMode(ballast4ValveWaterExit, OUTPUT);
  pinMode(ballast4ValveCO2Entry, OUTPUT);
  pinMode(ballast4ValveCO2Exit, OUTPUT);

  pinMode(waterPump, OUTPUT);
  pinMode(thrusterLeft, OUTPUT);
  pinMode(thrusterRight, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // example of turning one on then off
  digitalWrite(thrusterRight, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(thrusterRight, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
