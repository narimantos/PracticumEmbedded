#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int counter = 0;


ISR(TIMER0_OVF_vect)
{
    counter++;
    if (counter >= 4) {
        PINB = (1<<PINB0);
        counter = 0;
    }
    TCNT0 = 11;
}

int main()
{
    DDRB = 0xFF;
    sei();
    TCCR0B |= (1 << CS02) | (1<< CS00);
    TIMSK0 |= (1<< TOIE0);
    TCNT0 = 11;
    
    while(1){
        //PINB |= (1<<PINB0);
        //_delay_ms(500);
    }
    return 0;
}
