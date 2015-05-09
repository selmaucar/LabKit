#include <18F452.h>
#DEVICE ADC=10
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD   // Denetleyici konfigürasyon ayarlar?
#use delay(clock=8000000)

#define sut1   pin_b3 // sut1 ifadesi pin_d0 ifadesine e?itleniyor
#define sut2   pin_b2 // sut2 ifadesi pin_d1 ifadesine e?itleniyor
#define sut3   pin_b1 // sut3 ifadesi pin_d2 ifadesine e?itleniyor
#define sut4   pin_b0 // sut3 ifadesi pin_d2 ifadesine e?itleniyor

#define sat1   pin_b7 // sat1 ifadesi pin_d4 ifadesine e?itleniyor
#define sat2   pin_b6 // sat2 ifadesi pin_d5 ifadesine e?itleniyor
#define sat3   pin_b5 // sat3 ifadesi pin_d6 ifadesine e?itleniyor
#define sat4   pin_b4 // sat4 ifadesi pin_d7 ifadesine e?itleniyor

int tus=0; // karakter tipinde de?i?ken tan?mlan?yor
int sevenseg_codes[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0xFF, 0x39, 0xBF, 0x76, 0x49};
int i;

void seven_segment(int i){
        output_bit(PIN_A4,1);
        output_bit(PIN_A5,1);
      output_bit(PIN_A3,bit_test(sevenseg_codes[i],0));
      output_bit(PIN_A2,bit_test(sevenseg_codes[i],1));
      output_bit(PIN_C1,bit_test(sevenseg_codes[i],2));
      output_bit(PIN_C2,bit_test(sevenseg_codes[i],3));
      output_bit(PIN_C3,bit_test(sevenseg_codes[i],4));
      output_bit(PIN_C4,bit_test(sevenseg_codes[i],5));
      output_bit(PIN_C5,bit_test(sevenseg_codes[i],6));
      output_bit(PIN_C0,bit_test(sevenseg_codes[i],7));

}

int keypad_oku() // Fonksiyon ismi
{
   output_b(0x00); // D portu ç?k??? s?f?rlan?yor

   output_high(sat1); // 1. sat?r lojik-1 yap?l?yor
   if (input(sut1))   // 1. sütun okunuyor
      { delay_ms(20); tus=1; }
   if (input(sut2))   // 2. sütun okunuyor
      { delay_ms(20); tus=2; }
   if (input(sut3))   // 3. sütun okunuyor
      { delay_ms(20); tus=3; }
   if (input(sut4))   // 4. sütun okunuyor
      { delay_ms(20); tus=0xA; }
   output_low(sat1); // 1. sat?r lojik-0 yap?l?yor

   output_high(sat2); // 2. sat?r lojik-1 yap?l?yor
   if (input(sut1))   // 1. sütun okunuyor
      { delay_ms(20); tus=4; }
   if (input(sut2))   // 2. sütun okunuyor
      { delay_ms(20); tus=5; }
   if (input(sut3))   // 3. sütun okunuyor
      { delay_ms(20); tus=6; }
   if (input(sut4))   // 4. sütun okunuyor
      { delay_ms(20); tus=0xB; }
   output_low(sat2); // 2. sat?r lojik-0 yap?l?yor

   output_high(sat3); // 3. sat?r lojik-1 yap?l?yor
   if (input(sut1))   // 1. sütun okunuyor
      { delay_ms(20); tus=7; }
   if (input(sut2))   // 2. sütun okunuyor
      { delay_ms(20); tus=8; }
   if (input(sut3))   // 3. sütun okunuyor
      { delay_ms(20); tus=9; }
   if (input(sut4))   // 4. sütun okunuyor
      {delay_ms(20); tus=0x0C; }
   output_low(sat3); // 3. sat?r lojik-0 yap?l?yor

   output_high(sat4); // 3. sat?r lojik-1 yap?l?yor
   if (input(sut1))   // 1. sütun okunuyor
      { delay_ms(20); tus=0xE; }
   if (input(sut2))   // 2. sütun okunuyor
      { delay_ms(20); tus=0; }
   if (input(sut3))   // 3. sütun okunuyor
      { delay_ms(20); tus=0xF; }
   if (input(sut4))   // 4. sütun okunuyor
      {delay_ms(20); tus=0xD; }
   output_low(sat4); // 3. sat?r lojik-0 yap?l?yor

   return tus; // Fonksiyon "tus" de?eri ile geri döner
}

void main() {

    while(1){
    tus = keypad_oku();
    seven_segment(tus);
    delay_ms(300);
    }
}