// Quick Demo of light sensor

// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

#define WAARDE1 200


int main(void) {
    
    uint16_t adcValue;
    DDRB=0x02;
    
    ADMUX |= (1 << REFS0);                  /* reference voltage on AVCC */
    ADCSRA |= (1 << ADPS2);                   /* ADC clock prescaler /16 */
    ADCSRA |= (1 << ADEN);                                 /* enable ADC */
    
    // ------ Event loop ------ //
    while (1) {
        
        ADCSRA |= (1 << ADSC| 1<<ADIF);                     /* start ADC conversion */
        while(~ADCSRA & (1<<ADIF));
        adcValue = ADC;                                     /* read ADC in */
        
        if(adcValue > WAARDE1 )
            PORTB |=(1<<PORTB1);
        
        else
            PORTB &= ~(1<<PORTB1);
        
        _delay_ms(250);
    }                                                  /* End event loop */
    return (0);                            /* This line is never reached */
}
