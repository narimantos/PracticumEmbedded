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

void vertraging(uint8_t w)
{
    uint16_t beginTijd = 0xFFFF;
    beginTijd -= (w*1000000/256)
    initTimer(beginTijd);
}
void initTimer(uint16_t beginTijd) {
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1<< TOIE0);
    TCNT1L = (beginTijd & 0xFF);
    TCNT1H = (beginTijd>>8) & 0xFF);
    
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
                vertraging(10);
                break;
            case '1':
                PORTB=0x02;
                rx='2';
                vertraging(5);
                break;
            default : PORTB=0;
        }
        
        
    }  
    
    return (0);                           
}
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
    PORTB |= (1<<PORTB0);
    
}

 void vertraging(uint8_t w)
 {
    for(int i=0;i<w;i++)
        _delay_ms(100);

 }

int main(void) {

    DDRB=0xFF;

    initUsart();

    sei();

    writeString("Voer in:\n\r");
    writeString("0, LED op B0 gaat 10 seconden aan.\n\r");
    writeString("1, LED op B1 gaat 5 seconden aan.\n\r");
    
    TCCR1B |= 1 << CS01 | 0 << CS00;
    TIMSK0 |= (1<< TOIE0);
  
  while (1) {


    switch(rx) {

    case '0': PORTB=0x01;
              rx='2';
              vertraging(100);
              break;
    case '1': PORTB=0x02;
              rx='2';
              vertraging(50);
              break;
    default : PORTB=0;
    }
    

  }  

  return (0);                           
}
