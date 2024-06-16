#include <Wire.h>

#define I2C_ADDRESS 0x50

float data;

void setup() 
{
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(requestCallback);
  Wire.onReceive(receiveCallback);
}

void loop() 
{
  delay(100);
}

void receiveCallback() 
{
  uint8_t buffer[sizeof(float)];

  char i = ((char) sizeof(float)) - 1; 

  while (Wire.available()) 
  {
    buffer[i] = Wire.read();
    i--;
  }

  memcpy(&data, buffer, sizeof(float));
}

void requestCallback()
{
  uint8_t buffer[sizeof(float)];
  memcpy(buffer, &data, sizeof(float));

  for (uint8_t i = 0; i < 4; i++)
    Wire.write(buffer[i]);
}
