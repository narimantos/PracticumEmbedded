// Quick Demo of light sensor

// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>


#define  tijdsduur1 5
#define  tijdsduur2 1
#define	 D  293.66
#define  Ds	311.13
#define  F	349.23
#define  G	392

void playNoot(float freq, uint16_t tijd);
void intro();

// -------- Functions --------- //

void initUsart()
{
    TCCR1A = (0 << WGM10) | (0 << WGM11) | (1 << COM1B0) | (0 << COM1B1);
    TCCR1B = (1 << WGM13) | (1 << WGM12);
    ICR1 = 0;
    OCR1AL = 0;
    OCR1BL = 0;
}

void vertraging(uint16_t w)
{
    for(int i=0;i<w;i++)
        _delay_ms(50);
}

int main(void) {
    
    DDRB=0xFF;
    
    initUsart();
    
    sei();
    
    while(1){
        intro();
        vertraging(10);
    }
    
    return (0);
}

void intro(){
    while (1) {
    playNoot(G,tijdsduur1);
    vertraging(tijdsduur2);
        playNoot(D,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(D,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(F,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(G,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(D,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(D,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(F,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(D,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(D,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(F,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(F,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(G,tijdsduur1);
        vertraging(tijdsduur2);
        playNoot(G,tijdsduur1);
        vertraging(tijdsduur2);
    }
}

void playNoot(float freq, uint16_t tijd){
    TCNT1 = 0x00;
    TCCR1B |= (1 << CS10);
    ICR1 = 1000000 / (uint16_t)(freq);
    vertraging(tijd);
    TCCR1B &= ~(1 << CS10);
}