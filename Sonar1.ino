#include <Wire.h>

void setup() 
{ Wire.begin();
  Serial.begin(9600);  
}
void loop()
{ getDistance();
  delay(200); 
}   

void getDistance()
{ Wire.beginTransmission(48); //0x30=48, 0x40=64 sensors address

  Wire.write(byte(81)); //0x50=81, byte send to sensor to give Distance in INCHES
  Wire.endTransmission();
  delay(70);
 
  Wire.requestFrom(48,2); //ask the sensor to send 2 BYTES
  if (2 <= Wire.available())
  {   int readinginCms = Wire.read();
      readinginCms     = readinginCms << 8;
      readinginCms    |= Wire.read();
      //Serial.print("readinginCms = ");
      Serial.println(readinginCms);
      
  } 
}
