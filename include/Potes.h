#include <Arduino.h>
#include <ResponsiveAnalogRead.h>

// Pines Potenciometros
#define PotVolumen 32
#define PotDelay 31

float Volumen = 0;
int DelayVal = 0;

// Pot Volumen
int readingPot_V = 0;
int potCState_V = 0;
int PotPState_V = 0;

int potVar_V = 0;
const int TIMEOUT_POT_V = 300;
const byte varthresholdPot_V = 20;
bool potMoving_V = true;
unsigned long PTimePot_V = 0;
unsigned long timePot_V = 0;
////////////////////////////////////////////////////
// Pot Delay
int readingPot_D = 0;
int potCState_D = 0;
int PotPState_D = 0;

int potVar_D = 0;
const int TIMEOUT_POT_D = 300;
const byte varthresholdPot_D = 20;
bool potMoving_D = true;
unsigned long PTimePot_D = 0;
unsigned long timePot_D = 0;
/////////////////////////////
ResponsiveAnalogRead PotVolRes(PotVolumen, true);
ResponsiveAnalogRead PotDelayRes(PotDelay, true);

// Potenciometro volumen
void LecturaPot_V()
{
    PotVolRes.update();

    PotVolRes.update();
    potCState_V = PotVolRes.getValue();

    potVar_V = abs(potCState_V - PotPState_V);

    if (potVar_V > varthresholdPot_V)
    {
        PTimePot_V = millis();
    }
    timePot_V = millis() - PTimePot_V;

    if (timePot_V < TIMEOUT_POT_V)
    {
        potMoving_V = true;
    }
    else
    {
        potMoving_V = false;
    }
    if (potMoving_V == true)
    {
        Volumen = (float)potCState_V / 1280.0;

        mixerMain.gain(0, Volumen);
        mixerMain.gain(1, Volumen);
        mixerMain.gain(2, Volumen);

        printVol(Volumen); // Imprime en pantalla el valor del volumen

        Serial.print(" Potenciometro_V: ");
        Serial.print(potCState_V);

        Serial.println();
        PotPState_V = potCState_V;
    }
}

// Potenciometro Delay
void LecturaPot_D()
{
    PotDelayRes.update();

    potCState_D = PotDelayRes.getValue();

    potVar_D = abs(potCState_D - PotPState_D);

    if (potVar_D > varthresholdPot_D)
    {
        PTimePot_D = millis();
    }
    timePot_D = millis() - PTimePot_D;

    if (timePot_D < TIMEOUT_POT_D)
    {
        potMoving_D = true;
    }
    else
    {
        potMoving_D = false;
    }

    if (potMoving_D == true)
    {

        DelayVal = map(potCState_D, 0, 1023, 1, 1000);

        PrintDel(DelayVal); // Imprime en pantalla el valor del delay

        Serial.print(" Potenciometro_D: ");
        Serial.print(potCState_D);

        Serial.println();
        PotPState_D = potCState_D;
    }
}

// Potenciometro volumen Config
void LecturaPot_V_C()
{
    PotVolRes.update();

    PotVolRes.update();
    potCState_V = PotVolRes.getValue();

    potVar_V = abs(potCState_V - PotPState_V);

    if (potVar_V > varthresholdPot_V)
    {
        PTimePot_V = millis();
    }
    timePot_V = millis() - PTimePot_V;

    if (timePot_V < TIMEOUT_POT_V)
    {
        potMoving_V = true;
    }
    else
    {
        potMoving_V = false;
    }
    if (potMoving_V == true)
    {

        printTouchConf(potCState_V);

        Serial.print(" Potenciometro_V: ");
        Serial.print(potCState_V);

        Serial.println();
        PotPState_V = potCState_V;
    }
}

// Potenciometro Delay
void LecturaPot_D_C()
{
    PotDelayRes.update();

    potCState_D = PotDelayRes.getValue();

    potVar_D = abs(potCState_D - PotPState_D);

    if (potVar_D > varthresholdPot_D)
    {
        PTimePot_D = millis();
    }
    timePot_D = millis() - PTimePot_D;

    if (timePot_D < TIMEOUT_POT_D)
    {
        potMoving_D = true;
    }
    else
    {
        potMoving_D = false;
    }

    if (potMoving_D == true)
    {

        printReleaseConf(potCState_D);

        Serial.print(" Potenciometro_D: ");
        Serial.print(potCState_D);

        Serial.println();
        PotPState_D = potCState_D;
    }
}
