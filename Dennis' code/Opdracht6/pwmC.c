//
//  pwmB.c
//  
//
//  Created by Dennis de Jong on 13/04/16.
//
//

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint16_t duty = 96;
int counter = 0;

ISR(TIMER0_OVF_vect)
{
    counter++;
    if (counter >= 4) {
		PORTB ^= (1<<PB1);
        if(duty == 64) {
			duty = 96;
		}
		if(duty == 96) {
			duty = 128;
		}
		if(duty == 128){
			duty = 64;
			
        }
        OCR1B = duty;
        counter = 0;
    }
    TCNT0 = 11;
}

void pwm_init()
{
    // initialize TCCR1 as per requirement, say as follows
    TCCR1A |= (1<<WGM10)|(1<<COM1B1)| (1<<WGM11);
    TCCR1B |= (1<<CS11);
    TCCR1C = 0;
    // make sure to make PB2 as output pin
    DDRB |= (1<<PB2) | (1<<PB1);
	OCR1B = duty;
}

void timer0_init() {
    TCCR0B |= (1 << CS02) | (1<< CS00);
    TIMSK0 |= (1<< TOIE0);
    TCNT0 = 11;
}

int main()
{

    sei();
    // initialize timer in PWM mode
    pwm_init();
    timer0_init();
    // run forever
    while(1)
    {

    }
    return 0;
}
