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
void pwm_init()
{
    // initialize TCCR1 as per requirement, say as follows
    TCCR1A |= (1<<WGM10)|(1<<COM1A1)| (1<<COM1A0)|(1<<WGM11);
    TCCR1B |= (1<<CS11);
    TCCR1C = 0;
    // make sure to make PB1 as output pin
    DDRB |= (1<<PB1);
}

void main()
{
    uint16_t duty = 0;
    
    // initialize timer in PWM mode
    pwm_init();
    
    // run forever
    while(1)
    {
        OCR1A = duty;
        duty += 102; // Increase descreases dutycycle with 10%; 1023/10 = 102,3 = 102
        if (duty > 0x3FF) {
            duty = 0;
        }
    }
}
