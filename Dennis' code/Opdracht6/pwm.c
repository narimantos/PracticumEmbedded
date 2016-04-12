#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
void pwm_init()
{
    // initialize TCCR0 as per requirement, say as follows
    TCCR0A |= (1<<WGM00)|(1<<COM0B1)|(1<<WGM01);
    TCCR0B |= (1<<CS00);
    
    // make sure to make OC0 pin (pin PB3 for atmega32) as output pin
    DDRB |= (1<<PB3);
}

void main()
{
    uint8_t duty;
    duty = 115;       // duty cycle = 45% of 255 = 114.75 = 115
    
    // initialize timer in PWM mode
    pwm_init();
    
    // run forever
    while(1)
    {
        OCR0B = duty;
    }
}