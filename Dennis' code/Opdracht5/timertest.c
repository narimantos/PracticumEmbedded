// Quick Demo of light sensor

// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#define LED_TOGGLE      PINB |= (1<<PINB0)

ISR(TIMER1_OVF_vect) {
    LED_TOGGLE;
}


int main(void) {
    
    DDRB = 0xFF;
    
    sei();

    
    TCCR1B |= (1 << CS01) | (0 << CS00);
    TIMSK1 |= (1<< TOIE0);
    
    while (1) {
        //LED_TOGGLE;
        //_delay_ms(500);
    }  
    
    return (0);                           
}
