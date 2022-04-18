#include <Wire.h>
#include <SparkFun_FS3000_Arduino_Library.h>

FS3000 fs;

void setup()
{
  Serial.begin(115200);
  Serial.println("Example 1 - Reading values from the FS3000");

  Wire.begin();

  if (fs.begin() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
  Serial.println("Sensor is connected properly.");
}

void loop()
{
    Serial.print("FS3000 Readings \tRaw: ");
    Serial.print(fs.readRaw()); // note, this returns an int from 0-3686

    Serial.print("\tm/s: ");
    Serial.print(fs.readMetersPerSecond()); // note, this returns a float from 0-7.23

    Serial.print("\tmph: ");
    Serial.println(fs.readMilesPerHour()); // note, this returns a float from 0-16.17

    delay(1000); // note, repsone time on the sensor is 125ms
}
