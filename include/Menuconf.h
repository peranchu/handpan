// Menu de Configuracion
byte StoreTouch = 0;
byte StoreRel = 0;

byte StoreTouchPre = 0;
byte StoreRelPre = 0;

void MenuConfig(bool flag)
{
    bool EstadoConf = flag;

    StoreTouchPre = EEPROM.read(0);
    StoreRelPre = EEPROM.read(1);

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(30, 0);
    display.println("Configuracion");
    display.drawLine(1, 15, 127, 15, WHITE);

    display.setCursor(0, 40);
    display.println("Release");

    display.setCursor(0, 25);
    display.println(StoreTouchPre);

    display.setCursor(80, 40);
    display.println("Touch");

    display.setCursor(80, 25);
    display.println(StoreRelPre);

    display.display();

    while (EstadoConf == true)
    {
        LecturaPot_D_C();

        LecturaPot_V_C();
        StoreTouch = ValorTouch;
        StoreRel = valorRelease;

        if (!digitalRead(27))
        {
            EEPROM.write(0, StoreTouch);
            EEPROM.write(1, StoreRel);

            delay(500);

            EstadoConf = false;
        }
    }
}
////////////////////////////////////
