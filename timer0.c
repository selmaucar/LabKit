#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

#INT_RTCC
void zaman(void){
   output_toggle(PIN_E0);
   set_timer0(0);
}

void main() {
    setup_timer_0(RTCC_INTERNAL | RTCC_DIV_128);
    enable_interrupts(INT_RTCC);
    enable_interrupts(GLOBAL);
    set_timer0(0);
    while(1){
        
    }
}