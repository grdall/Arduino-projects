


const int rgbRedPin = 4;
const int rgbGreenPin = 3;
const int rgbBluePin = 2;
const int rbgPins[] = {rgbRedPin, rgbGreenPin, rgbBluePin};

const int redPin = 9;
const int yellowPin = 10;
const int greenPin = 11;

int onValue = 255;
int offValue = 0;
int blinkCycle = 1000;
int changeCycleTime = 8000;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{ 
  // Turn RBG LED pedestrian light red to tell pedestrians to stop, turn traffic light green so cars can go, wait 8 seconds
  stopPedestrians();
  startTraffic();
  delay(changeCycleTime);
  
  // Blink traffic light orange to signal coming red, wait 4 seconds
  haltTraffic();
  delay(changeCycleTime / 2);
  
  // Turn RGB LED pedestrian light green, turn traffic light red, wait 8 seconds
  stopTraffic();
  startPedestrians();
  delay(changeCycleTime);

  // Blink RGB LED pedestrian light green to signal coming red. The loop will continue from the top after the last blink.
  haltPedestrians();
}

void haltPedestrians()
{
  int offs[] = {offValue, offValue, offValue};
  int ons[] = {offValue, onValue, offValue};
  blink(rbgPins, offs, ons, 4, blinkCycle);
}

void stopPedestrians()
{
  analogWrite(rgbGreenPin, offValue);
  analogWrite(rgbBluePin, offValue);
  analogWrite(rgbRedPin, onValue);
}

void startPedestrians()
{
  analogWrite(rgbRedPin, offValue);
  analogWrite(rgbBluePin, offValue);
  analogWrite(rgbGreenPin, onValue);
}

void haltTraffic()
{
  analogWrite(greenPin, offValue);
  analogWrite(yellowPin, onValue);
}

void stopTraffic()
{
  analogWrite(yellowPin, offValue);
  analogWrite(redPin, onValue);
}

void startTraffic()
{
  analogWrite(yellowPin, offValue);
  analogWrite(redPin, offValue);
  analogWrite(greenPin, onValue);
}

void blink(int pins[], int pinOffValues[], int pinOnValues[], int nBlinks, int cycle)
{    
  int size = sizeof(pins) + 1;
  
  for(int i = 0; i < nBlinks; i++)
  {
    for(int j = 0; j < size; j++)
    {
      analogWrite(pins[j], pinOffValues[j]);
    }
    delay(cycle / 2);
    
    for(int j = 0; j < size; j++)
    {
      analogWrite(pins[j], pinOnValues[j]);
    }
    delay(cycle / 2);
  }
}