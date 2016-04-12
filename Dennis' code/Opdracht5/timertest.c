// Quick Demo of light sensor

// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#define LED_TOGGLE      PINB |= (1<<PINB0)

void initTimer()
{
    TCCR1A = (0 << WGM10) | (0 << WGM11) | (1 << COM1B0) | (0 << COM1B1);
    TCCR1B = (1 << WGM13) | (1 << WGM12);
    TCNT1 = 0x00;
    TCCR1B |= (1 << CS10);
    ICR1 = 50000;
    OCR1AL = 0;
    OCR1BL = 0;
}



int main(void) {
    
    DDRB = 0xFF;
    
    sei();

    initTimer();
    while (1) {
        //LED_TOGGLE;
        //_delay_ms(500);
    }  
    
    return (0);                           
}
