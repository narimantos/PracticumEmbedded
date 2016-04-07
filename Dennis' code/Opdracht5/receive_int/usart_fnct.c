#include <avr/io.h>
#include <stdlib.h>

#include "usart_fnct.h"

void writeInt(int16_t nr)
{
   char buffer[8];
   itoa(nr,buffer,10);
   writeString(buffer);
}

void writeString(char* s)
{
     while(*s)
         writeChar(*s++);
}

void writeChar(char c)
{

   while(!(UCSR0A & (1<<UDRE0)));
        UDR0=c;
}

