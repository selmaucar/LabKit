#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#use rs232(uart1, baud=9600)

void main() {
    int sevenseg_codes[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    int i;

    while(1){
        output_bit(PIN_A4,1);
        output_bit(PIN_A5,1);
        for(i=0;i<10;i++){
      output_bit(PIN_A3,bit_test(sevenseg_codes[i],0));
      output_bit(PIN_A2,bit_test(sevenseg_codes[i],1));
      output_bit(PIN_C1,bit_test(sevenseg_codes[i],2));
      output_bit(PIN_C2,bit_test(sevenseg_codes[i],3));
      output_bit(PIN_C3,bit_test(sevenseg_codes[i],4));
      output_bit(PIN_C4,bit_test(sevenseg_codes[i],5));
      output_bit(PIN_C5,bit_test(sevenseg_codes[i],6));
      output_bit(PIN_C0,bit_test(sevenseg_codes[i],7));
      delay_ms(1000);
        }
    }
}
