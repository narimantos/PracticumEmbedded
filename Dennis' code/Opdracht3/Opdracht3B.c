//
//  Opdracht3B.c
//  
//
//  Created by Dennis de Jong on 06/04/16.
//
// ------- Preamble -------- //
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB = 0x1E;
    DDRD &= ~(1 << PD2);
    int getal = 1;
    while (1) {
        if (PIND & (1<<PD2)) {
            if(getal < 8){
                getal = (getal<<1);
            } else {
                getal = 1;
            }
            _delay_ms(250);
        }
        PORTB = (getal<<1);
    }
}