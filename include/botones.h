#include <Arduino.h>
#include <Bounce.h>

// LECTURA BOTONES
const int NumBtn = 4;
const int PinBtn[NumBtn] = {30, 29, 28, 27};

Bounce EscalaUp = Bounce(30, 30);
Bounce EscalaDown = Bounce(28, 30);

Bounce OctUp = Bounce(29, 30);
Bounce OctDown = Bounce(27, 30);

int Octave_index = 0; // Almacena la Octava Seleccionada


// ConfiguracionPines Botones
void PinConfBtn()
{
    for (int i = 0; i < NumBtn; i++)
    {
        pinMode(PinBtn[i], INPUT_PULLUP);
    }
    delay(1000);
}

///////////////////////////////////////

// Lectura de Botones
void LecturaBotones()
{
    EscalaUp.update();
    EscalaDown.update();

    OctUp.update();
    OctDown.update();

    // transposición
    if (EscalaUp.fallingEdge())
    {
        note_index++;

        if (note_index > 68)
        {
            note_index = 57;
        }
        if (padNumber > 8)
        {
            padNumber = 0;
        }
        Octave_index = 0;

        changeScale();

        transposicion();

        Serial.println("Transposicion");
    }

    // Escala Cabio
    if (EscalaDown.risingEdge())
    {
        scale_index++;
        padNumber--;
        // check for overflow
        if (scale_index > numOfScales)
        {
            scale_index = 0;
        }
        if (padNumber < 0)
        {
            padNumber = 7;
        }

        Octave_index = 0;

        changeScale();

        PrintScale();

        Serial.println("EscalaCambio");
        Serial.println(scale_index);
    }

    // Octava UP
    if (OctUp.risingEdge())
    {
        Octave_index++;

        if (Octave_index > 2)
        {
            Octave_index = 2;
        }
        PrintOctava(Octave_index);

        Serial.println(Octave_index);
        Serial.println("OCtUP");
    }

    // Octava DOWN
    if (OctDown.fallingEdge())
    {
        Octave_index--;

        if (Octave_index < -2)
        {
            Octave_index = -2;
        }
        PrintOctava(Octave_index);

        Serial.println(Octave_index);
        Serial.println("OCtDown");
    }
}
