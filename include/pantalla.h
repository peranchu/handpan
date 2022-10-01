// Imprime en Pantalla la Escala Octava y Transposicion
#include <Arduino.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

int ValorTouch = 0;
byte valorRelease = 0;

byte valaueEEpromTouch = 0;
byte ValueEEpromRel = 0;

// Pantalla Fija
void PrintPantalla()
{
    valaueEEpromTouch = EEPROM.read(0);
    ValueEEpromRel = EEPROM.read(1);
    delay(200);

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Escala");

    display.setCursor(50, 0);
    display.println(valaueEEpromTouch);

    display.setCursor(70, 0);
    display.println(ValueEEpromRel);
    display.drawLine(0, 30, 80, 30, WHITE);

    display.setCursor(0, 35);
    display.println("Transp");

    display.setCursor(60, 35);
    display.println("Oct");

    display.setCursor(100, 0);
    display.println("Vol");

    display.setCursor(100, 35);
    display.println("Del");

    display.display();
}

// Cmbios de Escala
void PrintScale()
{
    if (scale_index == 0)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 15, 70, 15, BLACK);
        display.display();

        display.println("Major");
        display.display();
    }

    if (scale_index == 1)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 15, 70, 15, BLACK);

        display.println("Minor");
        display.display();
    }

    if (scale_index == 2)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Akebono");
        display.display();
    }

    if (scale_index == 3)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Pygmy");
        display.display();
    }

    if (scale_index == 4)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Equinox");
        display.display();
    }

    if (scale_index == 5)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Sapphire");
        display.display();
    }

    if (scale_index == 6)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Gypsy");
        display.display();
    }

    if (scale_index == 7)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Slvrspring");
        display.display();
    }

    if (scale_index == 8)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Integral");
        display.display();
    }

    if (scale_index == 9)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("Dorian");
        display.display();
    }

    if (scale_index == 10)
    {
        display.setTextSize(1);
        display.setCursor(20, 15);
        display.fillRect(20, 10, 70, 15, BLACK);

        display.println("GldArcadia");
        display.display();
    }
}

// Cambios Transposición
void transposicion()
{
    if (note_index == 60)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("C");
        display.display();
    }

    if (note_index == 61)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("C#");
        display.display();
    }

    if (note_index == 62)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("D");
        display.display();
    }

    if (note_index == 63)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("Eb");
        display.display();
    }

    if (note_index == 64)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("E");
        display.display();
    }

    if (note_index == 65)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("F");
        display.display();
    }

    if (note_index == 66)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("F#");
        display.display();
    }

    if (note_index == 67)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("G");
        display.display();
    }

    if (note_index == 68)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("Ab");
        display.display();
    }

    if (note_index == 57)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("A");
        display.display();
    }

    if (note_index == 58)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("Bb");
        display.display();
    }

    if (note_index == 59)
    {

        display.fillRect(10, 55, 20, 64, BLACK);
        display.display();

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.println("B");
        display.display();
    }
}

// Imprime en pantalla el volumen
void printVol(float Volumen)
{
    int volprint = map(Volumen, 0.0, 0.8, 0, 100);
    display.setTextSize(1);
    display.fillRect(105, 12, 50, 12, BLACK);
    display.display();

    display.setCursor(105, 12);
    display.println(volprint);
    display.display();
}

// imprime en pantalla el Delay
void PrintDel(int delay)
{
    display.setTextSize(1);
    display.fillRect(105, 50, 50, 50, BLACK);
    display.display();

    display.setCursor(105, 50);
    display.println((int)delay / 10);
    display.display();
}

// Imprime la Octava
void PrintOctava(int Octava)
{
    display.setTextSize(1);
    display.fillRect(60, 55, 40, 55, BLACK);
    display.display();

    display.setCursor(60, 55);
    display.println(Octava);
    display.display();
}

//////////////////////////////////////////////////////
// Imprime en pantalla la configuracion
byte printTouchConf(float Touch)
{
    ValorTouch = (byte)map(Touch, 0, 1023, 0, 100);

    display.setTextSize(1);
    display.fillRect(80, 55, 50, 55, BLACK);
    display.display();

    display.setCursor(80, 55);
    display.println(ValorTouch);
    display.display();
}

// Imprime en pantalla de configuracion
byte printReleaseConf(int Delay)
{
    valorRelease = (byte)map(Delay, 0, 1023, 0, 100);

    display.setTextSize(1);
    display.fillRect(0, 55, 50, 55, BLACK);
    display.display();

    display.setCursor(0, 55);
    display.println(valorRelease);
    display.display();
}