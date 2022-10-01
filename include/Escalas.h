// EScalas Del Sistema

int scale_index = 0; // Almacena la Escala Seleccionada

int note_index = 57; // Comienzo de nota A
int padNumber = 0;

int numOfScales = 10;

int scale[9];

void changeScale()
{
    int root = note_index;

    if (scale_index == 0) // Escala Mayor 2,2,3,2,3,2,2  (WholeStep, WS, WS+HalfStep, WS, WS+HS, WS, WS)
    {
        scale[0] = root;
        scale[1] = root + 2;
        scale[2] = root + 4;
        scale[3] = root + 7;
        scale[4] = root + 9;
        scale[5] = root + 12;
        scale[6] = root + 14;
        scale[7] = root + 16;
        scale[8] = root + 19;
    }

    if (scale_index == 1) // Minor Scale  3,2,2,3,2,3,2
    {
        scale[0] = root;
        scale[1] = root + 3;
        scale[2] = root + 5;
        scale[3] = root + 7;
        scale[4] = root + 10;
        scale[5] = root + 12;
        scale[6] = root + 15;
        scale[7] = root + 17;
        scale[8] = root + 19;
    }

    if (scale_index == 2) // Akebono Scale  2,1,4,1,4,2,1
    {
        scale[0] = root;
        scale[1] = root + 2;
        scale[2] = root + 3;
        scale[3] = root + 7;
        scale[4] = root + 8;
        scale[5] = root + 12;
        scale[6] = root + 14;
        scale[7] = root + 15;
        scale[8] = root + 19;
    }

    if (scale_index == 3) // Pygmy Scale  2,1,4,3,2,2,1
    {
        scale[0] = root;
        scale[1] = root + 2;
        scale[2] = root + 3;
        scale[3] = root + 7;
        scale[4] = root + 10;
        scale[5] = root + 12;
        scale[6] = root + 14;
        scale[7] = root + 15;
        scale[8] = root + 19;
    }
    if (scale_index == 4) // Equinox Scale  4,1,2,2,2,1,4
    {
        scale[0] = root;
        scale[1] = root + 4;
        scale[2] = root + 5;
        scale[3] = root + 7;
        scale[4] = root + 9;
        scale[5] = root + 11;
        scale[6] = root + 12;
        scale[7] = root + 16;
        scale[8] = root + 17;
    }
    if (scale_index == 5) // Sapphire    3,2,4,1,2,3,2
    {
        scale[0] = root;
        scale[1] = root + 3;
        scale[2] = root + 5;
        scale[3] = root + 9;
        scale[4] = root + 10;
        scale[5] = root + 12;
        scale[6] = root + 15;
        scale[7] = root + 17;
        scale[8] = root + 21;
    }
    if (scale_index == 6) // Gypsy    1,3,1,2,1,2,2
    {
        scale[0] = root;
        scale[1] = root + 1;
        scale[2] = root + 4;
        scale[3] = root + 5;
        scale[4] = root + 7;
        scale[5] = root + 8;
        scale[6] = root + 10;
        scale[7] = root + 12;
        scale[8] = root + 13;
    }
    if (scale_index == 7) // Silver Spring  4,1,2,2,3,4,1
    {
        scale[0] = root;
        scale[1] = root + 4;
        scale[2] = root + 5;
        scale[3] = root + 7;
        scale[4] = root + 9;
        scale[5] = root + 12;
        scale[6] = root + 16;
        scale[7] = root + 17;
        scale[8] = root + 21;
    }
    if (scale_index == 8) // Integral  2,1,4,1,2,2,2
    {
        scale[0] = root;
        scale[1] = root + 2;
        scale[2] = root + 3;
        scale[3] = root + 7;
        scale[4] = root + 8;
        scale[5] = root + 10;
        scale[6] = root + 12;
        scale[7] = root + 14;
        scale[8] = root + 15;
    }
    if (scale_index == 9) // Dorian  2,1,2,2,2,3,2
    {
        scale[0] = root;
        scale[1] = root + 2;
        scale[2] = root + 3;
        scale[3] = root + 5;
        scale[4] = root + 7;
        scale[5] = root + 9;
        scale[6] = root + 12;
        scale[7] = root + 14;
        scale[8] = root + 15;
    }
    if (scale_index == 10) // Golden Arcadia  4,3,4,1,2,4,1
    {
        scale[0] = root;
        scale[1] = root + 4;
        scale[2] = root + 7;
        scale[3] = root + 11;
        scale[4] = root + 12;
        scale[5] = root + 14;
        scale[6] = root + 18;
        scale[7] = root + 19;
        scale[8] = root + 23;
    }
}