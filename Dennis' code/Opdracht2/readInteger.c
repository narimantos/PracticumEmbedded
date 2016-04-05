//
//  readInteger.c
//  
//
//  Created by Dennis de Jong on 08/03/16.
//
//

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


#define RxD PD0
#define TxD PD1

int readInteger(){
    //int i = '0';
    int value = 0, i = '0';
    /*while(i != 10 || i != 13){
        value += (i-'0');
        while(~UCSR0A & (1<<RXC0));
        i = UDR0;
    }*/
    while(i != 32) {
        value = value*10 + (i - '0');
        while(~UCSR0A & (1<<RXC0));
        i = UDR0;
    }
    return value;
}

int main(void) {
    
    UCSR0A |= (1 << U2X0);     //double usart snelheid i.v.m. nauwkwurigheid baudrate instelling.
    UCSR0B = (1 << TXEN0) |(1<<RXEN0);      // Enable  de USART Receiver
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); /* 8 data bits, 1 stop bit */
    
    UBRR0H=00;
    UBRR0L=12;  //baudrade 9600 bij
    
    DDRB = 0xff;
    int i = 0;

    while (1) {
        
        i = readInteger();
        PORTB = (0xFF & i);
        
    }                                           
    return (0);
}
