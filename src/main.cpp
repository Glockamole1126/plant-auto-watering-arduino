#include <Arduino.h>

// put function declarations here:
const int Dry = 400; // threshold to consider plant soil dry using soil moisture detector
const int Wet = 185; // treshold to consider soil moisture wet
const int plant_count = 3;

int sensorpins[plant_count] = { A0, A1, A2};
int Relaypins[plant_count] = { 2, 3, 4}; 

int soil_moisture_detect(int sensorpins){
  return analogRead(sensorpins);
}


void waterplants( int Relaypins, int durationMS = 3000){
  digitalWrite(Relaypins, LOW);
  delay(durationMS);
  digitalWrite(Relaypins, HIGH);
}



void setup() {
 
  Serial.begin(9600);
  for (int i = 0; i < plant_count; i++){
  pinMode(Relaypins[1], OUTPUT);
  digitalWrite(Relaypins[i], HIGH);

  }
}

void loop() {
  for (int i = 0; i < plant_count; i++) {
    int moisture = soil_moisture_detect(sensorpins[i]);
    Serial.println("plant" + String(i) + "moisture is:" + String(moisture));
  

    if (moisture > Dry){
      waterplants(Relaypins[i], 3000);
    }

    else if (moisture < Wet){
      continue;

    } 
    delay(500);

  }
  delay(10000);

}