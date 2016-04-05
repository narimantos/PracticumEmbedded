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
    int i = 0;
    int iVal = 16;
    if(UDR0 != 0){
        i = UDR0 - '0';
        UDR0 = 0;
    }
    /*while(iVal != 10 || iVal != 13){
        PORTB = 0xFF & iVal;
        if(UDR0 != 0){
            iVal = UDR0 - '0';
            UDR0 = 0;
        }

        /*if(UDR0 != 0){
            buffer = UDR0;
            UDR0 = 0;
            if(buffer >= '0' && buffer <= '9' ){
                i = i*10 + (buffer-'0');
            }
        }
    }*/
    return i;
}

int main(void) {
    
    UCSR0A |= (1 << U2X0);     //double usart snelheid i.v.m. nauwkwurigheid baudrate instelling.
    UCSR0B = (1 << RXEN0);     // Enable  de USART Receiver
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
