#include <Arduino.h>
#include <EEPROM.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#include <Audio.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Bounce.h>

#include "AudioDesing.h"
#include "configAudio.h"

#include <Adafruit_MPR121.h>
#include "iconos.h"

#include "note_freq.h"
#include "Escalas.h"
#include "pantalla.h"
#include "botones.h"
#include "Potes.h"
#include "Menuconf.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

bool Estado = false;

byte UmbralTouch = 0;
byte UmbralRelease = 0;

void EstadoSensores();

void setup()
{
  Serial.begin(115200);
  delay(10);

  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  delay(1000);

  // Botones
  PinConfBtn(); // Funcion de configuración de Botones "botones.h"

  if (!digitalRead(29))
  {
    Estado = true;
    MenuConfig(Estado);
  }

  if (!cap.begin(0x5A))
  {
    Serial.println("MPR121 not found, check wiring?");
    while (1)
      ;
  }
  Serial.println("MPR121 found!");

  UmbralTouch = EEPROM.read(0);
  UmbralRelease = EEPROM.read(1);
  delay(200);

  cap.setThreshholds(UmbralTouch, UmbralRelease);

  Wire.begin();
  delay(100);

  ConfigAudio();

  display.clearDisplay();
  display.setRotation(0);
  display.setTextWrap(true);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.drawBitmap(0, 0, artec, 128, 50, 1);
  display.setCursor(10, 54);
  display.println("Arte y Electronica");
  display.display();

  delay(3000);

  display.clearDisplay();

  display.drawBitmap(0, 0, handDrun, 128, 64, 1);
  display.setCursor(10, 54);
  display.display();

  delay(3000);

  changeScale(); // Inicio DE configuracion

  PrintPantalla();
  PrintScale();
  transposicion();
  PrintOctava(Octave_index);
}

void loop()
{
  currtouched = cap.touched();

  EstadoSensores();

  LecturaPot_V();

  LecturaPot_D();

  LecturaBotones();
}

// Comprueba si el sensor ha sido tocado o liberado
void EstadoSensores()
{
  for (uint8_t i = 0; i < 9; i++)
  {
    // PULSADOS
    //  it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)))
    {
      // Sensor 0
      if (i == 0)
      {
        if (Octave_index == 1)
          sine1.frequency(note_frequency[scale[0] + 12]);
        else if (Octave_index == -1)
          sine1.frequency(note_frequency[scale[0] - 12]);
        else if (Octave_index == 2)
          sine1.frequency(note_frequency[scale[0] + 24]);
        else if (Octave_index == -2)
          sine1.frequency(note_frequency[scale[0] - 24]);
        else
          sine1.frequency(note_frequency[scale[0]]);
        dc1.amplitude(1.0, 5);
      }

      // Sensor 1
      if (i == 1)
      {
        if (Octave_index == 1)
          sine2.frequency(note_frequency[scale[1] + 12]);
        else if (Octave_index == -1)
          sine2.frequency(note_frequency[scale[1] - 12]);
        else if (Octave_index == 2)
          sine2.frequency(note_frequency[scale[1] + 24]);
        else if (Octave_index == -2)
          sine2.frequency(note_frequency[scale[1] - 24]);
        else
          sine2.frequency(note_frequency[scale[1]]);
        dc2.amplitude(1.0, 5);
      }

      // Sensor 2
      if (i == 2)
      {
        if (Octave_index == 1)
          sine3.frequency(note_frequency[scale[2] + 12]);
        else if (Octave_index == -1)
          sine3.frequency(note_frequency[scale[2] - 12]);
        else if (Octave_index == 2)
          sine3.frequency(note_frequency[scale[2] + 24]);
        else if (Octave_index == -2)
          sine3.frequency(note_frequency[scale[2] - 24]);
        else
          sine3.frequency(note_frequency[scale[2]]);
        dc3.amplitude(1.0, 5);
      }

      // Sensor 3
      if (i == 3)
      {
        if (Octave_index == 1)
          sine4.frequency(note_frequency[scale[3] + 12]);
        else if (Octave_index == -1)
          sine4.frequency(note_frequency[scale[3] - 12]);
        else if (Octave_index == 2)
          sine4.frequency(note_frequency[scale[3] + 24]);
        else if (Octave_index == -2)
          sine4.frequency(note_frequency[scale[3] - 24]);
        else
          sine4.frequency(note_frequency[scale[3]]);
        dc4.amplitude(1.0, 5);
      }

      // Sensor 4
      if (i == 4)
      {
        if (Octave_index == 1)
          sine5.frequency(note_frequency[scale[4] + 12]);
        else if (Octave_index == -1)
          sine5.frequency(note_frequency[scale[4] - 12]);
        else if (Octave_index == 2)
          sine5.frequency(note_frequency[scale[4] + 24]);
        else if (Octave_index == -2)
          sine5.frequency(note_frequency[scale[4] - 24]);
        else
          sine5.frequency(note_frequency[scale[4]]);
        dc5.amplitude(1.0, 5);
      }

      // Sensor 5
      if (i == 5)
      {
        if (Octave_index == 1)
          sine6.frequency(note_frequency[scale[5] + 12]);
        else if (Octave_index == -1)
          sine6.frequency(note_frequency[scale[5] - 12]);
        else if (Octave_index == 2)
          sine6.frequency(note_frequency[scale[5] + 24]);
        else if (Octave_index == -2)
          sine6.frequency(note_frequency[scale[5] - 24]);
        else
          sine6.frequency(note_frequency[scale[5]]);
        dc6.amplitude(1.0, 5);
      }

      // Sensor 6
      if (i == 6)
      {
        if (Octave_index == 1)
          sine7.frequency(note_frequency[scale[6] + 12]);
        else if (Octave_index == -1)
          sine7.frequency(note_frequency[scale[6] - 12]);
        else if (Octave_index == 2)
          sine7.frequency(note_frequency[scale[6] + 24]);
        else if (Octave_index == -2)
          sine7.frequency(note_frequency[scale[6] - 24]);
        else
          sine7.frequency(note_frequency[scale[6]]);
        dc7.amplitude(1.0, 5);
      }

      // Sensor 7
      if (i == 7)
      {
        if (Octave_index == 1)
          sine8.frequency(note_frequency[scale[7] + 12]);
        else if (Octave_index == -1)
          sine8.frequency(note_frequency[scale[7] - 12]);
        else if (Octave_index == 2)
          sine8.frequency(note_frequency[scale[7] + 24]);
        else if (Octave_index == -2)
          sine8.frequency(note_frequency[scale[7] - 24]);
        else
          sine8.frequency(note_frequency[scale[7]]);
        dc8.amplitude(1.0, 5);
      }

      // Sensor 8
      if (i == 8)
      {
        if (Octave_index == 1)
          sine9.frequency(note_frequency[scale[8] + 12]);
        else if (Octave_index == -1)
          sine9.frequency(note_frequency[scale[8] - 12]);
        else if (Octave_index == 2)
          sine9.frequency(note_frequency[scale[8] + 24]);
        else if (Octave_index == -2)
          sine9.frequency(note_frequency[scale[8] - 24]);
        else
          sine9.frequency(note_frequency[scale[8]]);
        dc9.amplitude(1.0, 5);
      }

      Serial.print(i);
      Serial.println(" touched");
    }

    // APAGADOS
    //  if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)))
    {
      // Sensor 1
      if (i == 0)
      {
        dc1.amplitude(0, DelayVal);
      }

      // Sensor 2
      if (i == 1)
      {

        dc2.amplitude(0, DelayVal);
      }

      // Sensor 3
      if (i == 2)
      {

        dc3.amplitude(0, DelayVal);
      }

      // Sensor 4
      if (i == 3)
      {

        dc4.amplitude(0, DelayVal);
      }

      // Sensor 5
      if (i == 4)
      {

        dc5.amplitude(0, DelayVal);
      }

      // Sensor 6
      if (i == 5)
      {

        dc6.amplitude(0, DelayVal);
      }

      // Sensor 7
      if (i == 6)
      {

        dc7.amplitude(0, DelayVal);
      }

      // Sensor 8
      if (i == 7)
      {

        dc8.amplitude(0, DelayVal);
      }

      // Sensor 9
      if (i == 8)
      {

        dc9.amplitude(0, DelayVal);
      }

      Serial.print(i);
      Serial.println(" released");
    }
  }
  // reset our state
  lasttouched = currtouched;
}
