#include <18F452.h>
#DEVICE ADC=10
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#include "flex_lcd.c"

void main() {
    lcd_init();
    setup_adc_ports(AN0);
    setup_adc(ADC_CLOCK_INTERNAL);
    set_adc_channel(0);
    while(1){
    printf(lcd_putc,"\fSayi=%ld",read_adc());
    delay_ms(100);
    }
}