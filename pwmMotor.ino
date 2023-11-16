uint8_t buttonPin = 3;
uint8_t motorPin = 4;
uint8_t potentioPin = 5;
uint8_t buttonHold = 0;
uint8_t prevPress = LOW;
uint8_t currPress;
bool State = LOW;

int PWMChannel = 0;
int PWMFreq = 5000;
int PWMResolution = 10;
int MAX_DUTY_CYCLE = 1023;
int dutyCycle;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(potentioPin, INPUT);
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(motorPin, PWMChannel);
}
void loop() {
  currPress = digitalRead(buttonPin);
  if (currPress != prevPress) {
    if (currPress == HIGH) {
      State = !State;
    }
    prevPress = currPress;
  }
  if (State == HIGH) {
    ledcWrite(PWMChannel, dutyCycle);
    dutyCycle = analogRead(potentioPin);
  } else {
    ledcWrite(PWMChannel, dutyCycle);
    dutyCycle = 0;
  }
}
