#include <stdint.h>

typedef uint8_t byte;	// 8-bit unsigned

byte* TextScreen = (byte*)(0x0400);
byte i, x, y = 8;

#define PutSpace() TextScreen[x + 40*y] = ' '
#define PutStar() TextScreen[x + 40*y] = '*'

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


void DrawLine(byte line)
{
  x = 8;
  for (i = 7; i > 0; --i)
  {
    if (PatternData[line] >> i & 1)
      PutStar();
    else
      PutSpace();
    ++x;
  }
  
  {
    if (line > 2)
      PutStar();
    else
      PutSpace();
    ++x;
  }
  
  for (i = 1; i < 8; ++i)
  {
    if (PatternData[line] >> i & 1)
      PutStar();
    else
      PutSpace();
    ++x;
  }
  ++y;
}

void main(void)
{
  byte i;
  for (i = 0; i < 8; ++i)
    DrawLine(i);
  for (i = 8; i != 255; --i)
    DrawLine(i);
}
