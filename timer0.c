#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

//timer hesap uygulamasi 
//http://www.libstock.com/projects/view/398/timer-calculator

#INT_RTCC
void zaman(void){
   output_toggle(PIN_E0);
   set_timer0(3036);
}

void main() {
    setup_timer_0(RTCC_INTERNAL | RTCC_DIV_32);
    enable_interrupts(INT_RTCC);
    enable_interrupts(GLOBAL);
    set_timer0(3036);
    while(1){}
}