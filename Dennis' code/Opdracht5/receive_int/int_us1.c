// Quick Demo of light sensor

// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "usart_fnct.h"

// -------- Functions --------- //

volatile char rx='2';

void initUsart()
{
    UCSR0A |= (1 << U2X0);
    UCSR0B = (1 << TXEN0) |(1<<RXEN0) | (1<<RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    UBRR0H=00;  UBRR0L=12;
}

ISR(USART_RX_vect)
{
    rx=UDR0;
}

ISR(TIMER1_OVF_vect) {
    PORTB = 0;
    TCCR1B |= 0;
    TIMSK1 &= ~(1<< TOIE0);
}

void timer( uint8_t w) {
    
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1<< TOIE0);
    TCNT1 = 0xFFFF-(w*(1000000/256));

}



int main(void) {
    
    DDRB=0xFF;
    
    initUsart();
    
    sei();
    
    writeString("Voer in:\n\r");
    writeString("0, LED op B0 gaat 10 seconden aan.\n\r");
    writeString("1, LED op B1 gaat 5 seconden aan.\n\r");
    
    
    
    while (1) {
        
        
        switch(rx) {
                
            case '0':
                PORTB=0x01;
                rx='2';
                timer(10);
                break;
            case '1':
                PORTB=0x02;
                rx='2';
                timer(5);
                break;
        }
        
        
    }  
    
    return (0);                           
}