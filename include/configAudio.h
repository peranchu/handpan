void ConfigAudio()
{
    // set aside audio memory
    AudioMemory(64);

    // initialize audio settings
    sine1.amplitude(0.125);
    sine1.frequency(440);
    sine2.amplitude(0.125);
    sine2.frequency(440);
    sine3.amplitude(0.125);
    sine3.frequency(440);
    sine4.amplitude(0.125);
    sine4.frequency(440);
    sine5.amplitude(0.125);
    sine5.frequency(440);
    sine6.amplitude(0.125);
    sine6.frequency(440);
    sine7.amplitude(0.125);
    sine7.frequency(440);
    sine8.amplitude(0.125);
    sine8.frequency(440);
    sine9.amplitude(0.125);
    sine9.frequency(440);

    dc1.amplitude(0);
    dc2.amplitude(0);
    dc3.amplitude(0);
    dc4.amplitude(0);
    dc5.amplitude(0);
    dc6.amplitude(0);
    dc7.amplitude(0);
    dc8.amplitude(0);
    dc9.amplitude(0);

    // initialize volume
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.8);
    sgtl5000_1.lineOutLevel(5);
}