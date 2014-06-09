/*
 * use case for the TinyDuino and the 7 Segment (dual digit)
 * shield. 
 */
#include <Wire.h>

void regwrite(byte reg, byte val) {
  Wire.beginTransmission(0x20);
  Wire.write(reg);
  Wire.write(val^0xff);
  Wire.endTransmission();
}

void setup () {
  Wire.begin();
  Wire.beginTransmission(0x20);
  Wire.write(0x02);
  Wire.write(0);
  Wire.write(0);
  Wire.endTransmission();
}

static const unsigned char digits[16] = {
  0x3f,  // 0
  0x06,  // 1
  0x5b,  // 2
  0x4f,  // 3
  0x66,  // 4
  0x6d,  // 5
  0x7d,  // 6
  0x07,  // 7
  0x7f,  // 8
  0x6f,  // 9
  0x77,  // A
  0x7c,  // b
  0x39,  // C
  0x5e,  // d
  0x79,  // E
  0x71  // F
};

static const char loop1[16] = {
  0x01, 0x01,
  0x00, 0x03,
  0x00, 0x06,
  0x00, 0x0c,
  0x08, 0x08,
  0x18, 0x00,
  0x30, 0x00,
  0x21, 0x00
};

static const char loop2[24] = {
  0x03, 0x018,
  0x06, 0x30,
  0x0c, 0x21,
  0x18, 0x03,
  0x30, 0x06,
  0x21, 0x0c,
  0x30, 0x06,
  0x18, 0x03,
  0x0c, 0x21,
  0x06, 0x30,
  0x03, 0x18,
  0x40, 0x40
};


#define DP_SEG 0x80
#define A

void loop (){
  int ndx, i;

  for (ndx = 0; ndx < 16; ndx++) {
    regwrite(0, digits[ndx]);
    regwrite(1, digits[15 - ndx]);
    delay(300);
  }
  for (i = 0; i < 20; i++) {  
    for (ndx = 0; ndx < 16; ndx += 2) {
      regwrite(0, loop1[ndx]);
      regwrite(1, loop1[ndx+1]);
      delay(75);
    }
  }

  for (i = 0; i < 20; i++) {  
    for (ndx = 0; ndx < 24; ndx += 2) {
      regwrite(0, loop2[ndx]);
      regwrite(1, loop2[ndx+1]);
      delay(75);
    }
  }
}

