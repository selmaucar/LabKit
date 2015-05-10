#include <18F452.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

void main() {
    setup_timer_2(T2_DIV_BY_16,250,1);
    setup_ccp1(CCP_PWM);
    while(1){
    set_pwm1_duty(125);
    delay_ms(500);
    set_pwm1_duty(0);
    delay_ms(500);
    }
}