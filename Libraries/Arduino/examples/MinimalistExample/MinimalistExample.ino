// I2C interface by default
//
#include "Wire.h"
#include "SparkFunIMU.h"
#include "SparkFunLSM303C.h"
#include "LSM303CTypes.h"


const int LM303GND = 15; //D8
const int LM303SCL = 13;// D7
const int LM303SDA = 12; //D6


// #define DEBUG 1 in SparkFunLSM303C.h turns on debugging statements.
// Redefine to 0 to turn them off.

LSM303C myIMU;

void setup()
{
   Wire.begin(LM303SDA, LM303SCL);
  pinMode(LM303GND,OUTPUT);
  digitalWrite(LM303GND, LOW);

  
  Serial.begin(115200);
  if (myIMU.begin() != IMU_SUCCESS)
  {
    Serial.println("Failed setup.");
    while(1);
  }
}

void loop()
{
  //Get all parameters
  /*
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X = ");
  Serial.println(myIMU.readAccelX(), 4);
  Serial.print(" Y = ");
  Serial.println(myIMU.readAccelY(), 4);
  Serial.print(" Z = ");
  Serial.println(myIMU.readAccelZ(), 4);
  */

  char sbuf[200];
  sprintf(sbuf, "Mag: X=%.2f\tY=%.2f\tZ=%.2f \tAccel X=%.2f\tY=%.2f\tZ=%.2f", myIMU.readMagX(),myIMU.readMagY(),myIMU.readMagZ(),myIMU.readAccelX(),myIMU.readAccelY(),myIMU.readAccelZ() );
  Serial.println(sbuf);  
  // Not supported by hardware, so will return NAN
  /*
  Serial.print("\nGyroscope:\n");
  Serial.print(" X = ");
  Serial.println(myIMU.readGyroX(), 4);
  Serial.print(" Y = ");
  Serial.println(myIMU.readGyroY(), 4);
  Serial.print(" Z = ");
  Serial.println(myIMU.readGyroZ(), 4);
*/
  /*
  Serial.print("\nMagnetometer:\n");
  Serial.print(" X = ");
  Serial.println(myIMU.readMagX(), 4);
  Serial.print(" Y = ");
  Serial.println(myIMU.readMagY(), 4);
  Serial.print(" Z = ");
  Serial.println(myIMU.readMagZ(), 4);

  Serial.print("\nThermometer:\n");
  Serial.print(" Degrees C = ");
  Serial.println(myIMU.readTempC(), 4);
  Serial.print(" Degrees F = ");
  Serial.println(myIMU.readTempF(), 4);
  */
  delay(100);
}