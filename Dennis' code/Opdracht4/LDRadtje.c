//
//  adtje.c
//
//
//  Created by Dennis de Jong on 06/04/16.
//
//
// Quick Demo of light sensor

// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>




int main(void) {
    int waarde1;
    
    uint16_t adcValuePot;
    uint16_t adcValueLDR;
    DDRB=0x02;
    
    ADMUX |= (1 << REFS0);                  /* reference voltage on AVCC */
    ADCSRA |= (1 << ADPS2);                   /* ADC clock prescaler /16 */
    ADCSRA |= (1 << ADEN);                                 /* enable ADC */
    
    
    // ------ Event loop ------ //
    while (1) {
        ADMUX &= ~(1<<MUX0);
        ADCSRA |= (1 << ADSC| 1<<ADIF);                     /* start ADC conversion */
        while(~ADCSRA & (1<<ADIF));
        adcValuePot = ADC;                                     /* read ADC in */
        
        waarde1 = adcValuePot;
        
        ADMUX |= (1<<MUX0);
        ADCSRA |= (1 << ADSC| 1<<ADIF);                     /* start ADC conversion */
        while(~ADCSRA & (1<<ADIF));
        adcValueLDR = ADC;
        
        if(adcValueLDR > waarde1 )
            PORTB |=(1<<PORTB1);
        
        else
            PORTB &= ~(1<<PORTB1);
        
        _delay_ms(250);
    }                                                  /* End event loop */
    return (0);                            /* This line is never reached */
}
