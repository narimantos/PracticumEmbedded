
#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define RxD PD0
#define TxD PD1

void writeChar(char c){
    while(~UCSR0A & (1<<UDRE0));
    UDR0 = c;
}

void writeString(char st[]) {
    for(uint8_t i = 0 ; st[i] != 0 ; i++) {
        writeChar( st[i] );
    }
}

void writeInt(int i) {
    char buffer[8];
    itoa(i,buffer,10);
    writeString(buffer);
}

int main(void) {
  
  UCSR0A |= (1 << U2X0);     //double usart snelheid i.v.m. nauwkwurigheid baudrate instelling.
  UCSR0B = (1 << TXEN0);     // Enable  de USART Transmitter
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); /* 8 data bits, 1 stop bit */

  UBRR0H=00;
  UBRR0L=12;  //baudrade 9600 bij 

  while (1) {
    for(int i = 0; i <= 101; i++){
        writeInt(i);
        writeChar(' ');
        _delay_ms(1000);
    }

  }

  return (0);
}
