// POV toy demo framework //

// ------- Preamble -------- //
#define F_CPU 1000000 
#include <avr/io.h>
#include <util/delay.h>

// -------- Functions --------- //
void POVDisplay(uint8_t oneByte, uint8_t secByte) {
  PORTB = oneByte;
  PORTD = secByte;
  _delay_ms(500);
}

int main(void) {
  // -------- Inits --------- //
  DDRB = 0xff;                    /* Set up all of LED pins for output */
  DDRD = 0xff;
  // ------ Event loop ------ //
  while (1) {                                              /* mainloop */

    POVDisplay(0b00000000, 0b00000001);
    POVDisplay(0b00000000, 0b00000010);
    POVDisplay(0b00000001, 0b00000000);
    POVDisplay(0b00000010, 0b00000000);
    POVDisplay(0b00000100, 0b00000000);
    POVDisplay(0b00001000, 0b00000000);
    POVDisplay(0b00010000, 0b00000000);
    POVDisplay(0b00100000, 0b00000000);
    POVDisplay(0b01000000, 0b00000000);
    POVDisplay(0b10000000, 0b00000000);
    POVDisplay(0b01000000, 0b00000000);
    POVDisplay(0b00100000, 0b00000000);
    POVDisplay(0b00010000, 0b00000000);
    POVDisplay(0b00001000, 0b00000000);
    POVDisplay(0b00000100, 0b00000000);
    POVDisplay(0b00000010, 0b00000000);
    POVDisplay(0b00000001, 0b00000000);
    POVDisplay(0b00000000, 0b00000010);

    PORTB = 0;
    PORTD = 0;
    _delay_ms(10);
  }                                                    /* end mainloop */
  return (0);
}
