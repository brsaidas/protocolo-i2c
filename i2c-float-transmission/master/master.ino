#include <Wire.h>

#define SLAVE_ADDRESS 0x50

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  Wire.beginTransmission(SLAVE_ADDRESS);
  I2CWriteFloat(220.0);
  Wire.endTransmission();

  delay(100);

  Wire.requestFrom(SLAVE_ADDRESS, 4);

  Serial.println(I2CReadFloat());

  delay(100);
}

void I2CWriteFloat(float value)
{
  uint8_t buffer[sizeof(float)];

  memcpy(buffer, &value, sizeof(float));

  for (uint8_t i = 0; i < 4; i++)
    Wire.write(buffer[i]);
}

float I2CReadFloat()
{
  uint8_t buffer[sizeof(float)];

  char i = ((char) sizeof(float)) - 1;  

  while (Wire.available()) 
  {
    buffer[i] = Wire.read();
    i--;
  }

  float aux;

  memcpy(&aux, buffer, sizeof(float));

  return aux;
}

String ByteToBin(uint8_t byte) 
{
  String buffer = "";
  for (int i = 7; i >= 0; i--)
    buffer += (byte & (1 << i)) ? '1' : '0';

  return buffer;
}