#include <stdint.h>
typedef uint8_t byte;	// 8-bit unsigned

byte* TextScreen = (byte*)(0x0400);
byte i, x, z, line = 0;
#define XCorner 8

byte PatternData[9] =
{
0b00001000,
0b00001100,
0b00001110,
0b00001111,
0b11111111,
0b01111111,
0b00111111,
0b00011111,
0b00001111
};

void PutChar(char q)
{
  TextScreen[x + 40*z] = q;
  TextScreen[30 - x + 40*z] = q;
  ++x;
}
void Draw(byte r)
{
  if (PatternData[r] >> i & 1)
    PutChar('*');
  else
    PutChar(' ');
}

void main(void)
{    
  for (z = 0; z < 17; ++z)
  {
    x = XCorner;
    line = z;
    if (line > 7)
      line  = 8 - (line - 8);
    for (i = 7; i > 0; --i)
    {
      Draw(line);
    }
    
    if (line > 2)
      PutChar('*');
    else
      PutChar(' ');
  }
}