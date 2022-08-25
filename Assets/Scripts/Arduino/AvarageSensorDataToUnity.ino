#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "EMGFilters.h"
#define TIMING_DEBUG 1
#define SensorInputPin A0 // input pin number

EMGFilters myFilter;
int sampleRate = SAMPLE_FREQ_500HZ;
int humFreq = NOTCH_FREQ_50HZ;

static int Threshold = 0;
static int ResetTime = 5000;

float Output = 0;
int Highvalue = 200000;
long dataAmount = 10;
long sum = 0;

signed long timeStamp;
unsigned long timeBudget;

void setup() {
  myFilter.init(sampleRate, humFreq, true, true, true);

  Serial.begin(115200);

  timeBudget = 1e6 / sampleRate;
}

int count = 0;

void loop() {
  timeStamp = micros();
  int Value = analogRead(SensorInputPin);
  
  // filter processing
  int DataAfterFilter = myFilter.update(Value);
  
  int envlope = DataAfterFilter * DataAfterFilter;
  //output data to Serial 
  //Serial.println(envlope);
  // any value under threshold will be set to zero
  envlope = (envlope > Threshold) ? envlope : 0;
  // any value above High will be set High
  envlope = (envlope < Highvalue) ? envlope : Highvalue;
  
  if( count < dataAmount )
  {
    sum = sum + envlope;
    count = count + 1;
  }
  
  if( count >= dataAmount)
  {
    Output = sum / dataAmount;
    Output = map(Output, 0, Highvalue, 0, 100);
    //Output average data to serial 
    //Serial.println(Output);
    count = 0;
    Output = 0;
    sum = 0;
  }
  delay(50);
}
