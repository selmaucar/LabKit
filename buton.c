#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

void main() {
set_tris_e(0x00); //e portu output
set_tris_d(0xC0);
while(TRUE) {
    if(input(PIN_D7)==0){
      	output_high(PIN_E1);	//e1 high
		delay_ms(200);
    }
    else {
        output_low(PIN_E1);	//e1 high
		delay_ms(200);
    }
   }
}