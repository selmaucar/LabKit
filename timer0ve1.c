#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

#INT_RTCC
void zaman(void){
   output_toggle(PIN_E0);
   set_timer0(3036);
}

#INT_TIMER1
void timer1zaman(void){
    output_toggle(PIN_E1);
    set_timer1(15536);
}

void main() {
    setup_timer_0(RTCC_INTERNAL | RTCC_DIV_32);
    setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
    enable_interrupts(INT_RTCC);
    enable_interrupts(INT_TIMER1);
    enable_interrupts(GLOBAL);
    set_timer0(3036);
    set_timer1(15536);
    while(1){}
}