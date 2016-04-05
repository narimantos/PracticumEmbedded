
#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


#define RxD PD0
#define TxD PD1



int main(void) {
  
  UCSR0A |= (1 << U2X0);     //double usart snelheid i.v.m. nauwkwurigheid baudrate instelling.
  UCSR0B = (1 << TXEN0);     // Enable  de USART Transmitter
  UCSR0C = (1 << UCSZ01) | (1 << UPM01); /* 7 data bits, 1 stop bit */

  UBRR0H=00;
  UBRR0L=12;  //baudrade 9600 bij 

  while (1) {

    for(char c='0'; c<='9';c++)
    {
      while(~UCSR0A & (1<<UDRE0));
      UDR0 = c;  
      for(uint8_t i=0;i<4;++i)
         _delay_ms(250);
    }   

  }                                           
  return (0);
}
