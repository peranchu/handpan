
// GUItool: begin automatically generated code
AudioSynthWaveformDc     dc2;            //xy=88,213
AudioSynthWaveformSine   sine3;          //xy=88,257
AudioSynthWaveformDc     dc6;            //xy=87,571
AudioSynthWaveformSine   sine7;          //xy=87,615
AudioSynthWaveformSine   sine2;          //xy=89,171
AudioSynthWaveformSine   sine6;          //xy=88,529
AudioSynthWaveformDc     dc1;            //xy=90,125
AudioSynthWaveformSine   sine9; //xy=88,782
AudioSynthWaveformSine   sine1;          //xy=91,85
AudioSynthWaveformSine   sine4;          //xy=90,341
AudioSynthWaveformSine   sine5;          //xy=90,443
AudioSynthWaveformSine   sine8;          //xy=89,699
AudioSynthWaveformDc     dc5;            //xy=90,485
AudioSynthWaveformDc     dc9; //xy=89,826
AudioSynthWaveformDc     dc4;            //xy=91,385
AudioSynthWaveformDc     dc8;            //xy=90,743
AudioSynthWaveformDc     dc3;            //xy=93,301
AudioSynthWaveformDc     dc7;            //xy=92,659
AudioEffectMultiply      multiply3;      //xy=245,275
AudioEffectMultiply      multiply9; //xy=243,802
AudioEffectMultiply      multiply4;      //xy=245,361
AudioEffectMultiply      multiply7;      //xy=244,633
AudioEffectMultiply      multiply8;      //xy=244,719
AudioEffectMultiply      multiply2;      //xy=249,191
AudioEffectMultiply      multiply6;      //xy=248,549
AudioEffectMultiply      multiply1;      //xy=252,102
AudioEffectMultiply      multiply5;      //xy=251,460
AudioMixer4              mixer3; //xy=423,763
AudioMixer4              mixer2;         //xy=434,545
AudioMixer4              mixer1;         //xy=464,252
AudioMixer4              mixerMain;      //xy=635,425
AudioOutputI2S           i2s1;           //xy=780,473
AudioConnection          patchCord1(dc2, 0, multiply2, 1);
AudioConnection          patchCord2(sine3, 0, multiply3, 0);
AudioConnection          patchCord3(dc6, 0, multiply6, 1);
AudioConnection          patchCord4(sine7, 0, multiply7, 0);
AudioConnection          patchCord5(sine2, 0, multiply2, 0);
AudioConnection          patchCord6(sine6, 0, multiply6, 0);
AudioConnection          patchCord7(dc1, 0, multiply1, 1);
AudioConnection          patchCord8(sine9, 0, multiply9, 0);
AudioConnection          patchCord9(sine1, 0, multiply1, 0);
AudioConnection          patchCord10(sine4, 0, multiply4, 0);
AudioConnection          patchCord11(sine5, 0, multiply5, 0);
AudioConnection          patchCord12(sine8, 0, multiply8, 0);
AudioConnection          patchCord13(dc5, 0, multiply5, 1);
AudioConnection          patchCord14(dc9, 0, multiply9, 1);
AudioConnection          patchCord15(dc4, 0, multiply4, 1);
AudioConnection          patchCord16(dc8, 0, multiply8, 1);
AudioConnection          patchCord17(dc3, 0, multiply3, 1);
AudioConnection          patchCord18(dc7, 0, multiply7, 1);
AudioConnection          patchCord19(multiply3, 0, mixer1, 2);
AudioConnection          patchCord20(multiply9, 0, mixer3, 0);
AudioConnection          patchCord21(multiply4, 0, mixer1, 3);
AudioConnection          patchCord22(multiply7, 0, mixer2, 2);
AudioConnection          patchCord23(multiply8, 0, mixer2, 3);
AudioConnection          patchCord24(multiply2, 0, mixer1, 1);
AudioConnection          patchCord25(multiply6, 0, mixer2, 1);
AudioConnection          patchCord26(multiply1, 0, mixer1, 0);
AudioConnection          patchCord27(multiply5, 0, mixer2, 0);
AudioConnection          patchCord28(mixer3, 0, mixerMain, 2);
AudioConnection          patchCord29(mixer2, 0, mixerMain, 1);
AudioConnection          patchCord30(mixer1, 0, mixerMain, 0);
AudioConnection          patchCord31(mixerMain, 0, i2s1, 0);
AudioConnection          patchCord32(mixerMain, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=427,416
// GUItool: end automatically generated code

