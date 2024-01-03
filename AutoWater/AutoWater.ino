

#include <Wire.h>
#include <EEPROM.h>
#include "Arduino.h"



const int moistureSense{A1}; //moisture sensor port
const int relay = 6; //relay that controls the pump
double moisture = 1;
bool allowWater = true;
void setup() {

  pinMode(moistureSense, INPUT);
  pinMode(relay, OUTPUT);

}


void loop() {
moisture = analogRead(moistureSense);


/*the if statement uses the 'allowWater' bool to account for an inaccurate sensor and/or time it 
takes for water to make the soil moist, failure to do so may lead to overwatering.*/
  
  if(moisture <= 0.5 && allowWater) //moisiture value is dependent on sensor and will require testing
  {
    allowWater = false;
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW);
    delay(500000);
    allowWater = true; 

  }

}
