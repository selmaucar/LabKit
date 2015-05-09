#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

void main() {
set_tris_e(0x00); //e portu output
while(TRUE) {
	output_high(PIN_E0);	//e1 high
	delay_ms(500);			//bekle
	output_low(PIN_E0);	//e2 high
	delay_ms(500);
   }
}