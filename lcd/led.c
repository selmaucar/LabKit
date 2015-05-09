#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#include "flex_lcd.c"

void main() {
set_tris_e(0x00); //e portu output
set_tris_d(0xC0);
lcd_init();
lcd_putc("\f");
lcd_putc("Fatih University");
while(TRUE) {
	output_high(PIN_E0);	//e1 high
	delay_ms(200);			//bekle
	output_low(PIN_E0);	//e2 high
	delay_ms(200);
   }
}