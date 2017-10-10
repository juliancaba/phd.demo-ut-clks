#include "hls_casting.h"


// union type32{
//   unsigned char c[4];
//   int i;
// };


union IEEE754_double_precision{
  unsigned char c[8];
  unsigned short s[4];
  unsigned int i[2];
  double d;
  long long ll;
};

union IEEE754_single_precision {
  unsigned int i;
  float f;
};



// Enteros
short
toShort(unsigned char c1, unsigned char c2)
{
  short aux;
  aux = (c1<<8) | c2;
  return aux;
}

int
toInt(unsigned char c1, unsigned char c2, 
      unsigned char c3, unsigned char c4)
{
  int aux;
  aux = (c4<<24)|(c3<<16)|(c2<<8)|c1;
  return aux;
}

int
toInt(unsigned short s1, unsigned short s2)
{
  int aux;
  aux = (s2<<16)|s1;
  return aux;
}

long long
toLongLong(unsigned char c1, unsigned char c2, 
	   unsigned char c3, unsigned char c4,
	   unsigned char c5, unsigned char c6, 
	   unsigned char c7, unsigned char c8)
{
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.c[7] = c1;
  castingIEEE754_dp.c[6] = c2;
  castingIEEE754_dp.c[5] = c3;
  castingIEEE754_dp.c[4] = c4;
  castingIEEE754_dp.c[3] = c5;
  castingIEEE754_dp.c[2] = c6;
  castingIEEE754_dp.c[1] = c7;
  castingIEEE754_dp.c[0] = c8;
  return castingIEEE754_dp.ll;
}

long long
toLongLong(unsigned short s1, unsigned short s2, 
	   unsigned short s3, unsigned short s4)
{
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.s[3] = s1;
  castingIEEE754_dp.s[2] = s2;
  castingIEEE754_dp.s[1] = s3;
  castingIEEE754_dp.s[0] = s4;
  return castingIEEE754_dp.ll;
}

long long
toLongLong(unsigned int i1, unsigned int i2)
{
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.i[1] = i1;
  castingIEEE754_dp.i[0] = i2;
  return castingIEEE754_dp.ll;
}

void
toSequence(short n, unsigned char bytes[2])
{
  bytes[0] = (n >> 8) & 0xFF;
  bytes[1] = n & 0xFF;
}

void
toSequence(int n, unsigned char bytes[4])
{
  bytes[3] = (n >> 24) & 0xFF;
  bytes[2] = (n >> 16) & 0xFF;
  bytes[1] = (n >> 8) & 0xFF;
  bytes[0] = n & 0xFF;
}

void
toSequence(int n, unsigned short words[2])
{
  words[1] = (n >> 16) & 0xFFFF;
  words[0] = n & 0xFFFF;
}

void
toSequence(long long n, unsigned char bytes[8])
{
  bytes[0] = (n >> 56) & 0xFF;
  bytes[1] = (n >> 48) & 0xFF;
  bytes[2] = (n >> 40) & 0xFF;
  bytes[3] = (n >> 32) & 0xFF;
  bytes[4] = (n >> 24) & 0xFF;
  bytes[5] = (n >> 16) & 0xFF;
  bytes[6] = (n >> 8) & 0xFF;
  bytes[7] = n & 0xFF;
}

void
toSequence(long long n, unsigned short words[4])
{
  words[0] = (n >> 48) & 0xFFFF;
  words[1] = (n >> 32) & 0xFFFF;
  words[2] = (n >> 16) & 0xFFFF;
  words[3] = n & 0xFFFF;
}

void
toSequence(long long n, unsigned int words[2])
{
  words[0] = (n >> 32) & 0xFFFFFFFF;
  words[1] = n & 0xFFFFFFFF;
}




// -----------
//  -- IEEE754
// ------------
float
toFloat(unsigned char c1, unsigned char c2, 
	unsigned char c3, unsigned char c4)
{
  union IEEE754_single_precision castingIEEE754_sp;
  castingIEEE754_sp.i = (c4<<24)|(c3<<16)|(c2<<8)|c1;
  return castingIEEE754_sp.f;
}

float
toFloat(unsigned short s1, unsigned short s2)
{
  union IEEE754_single_precision castingIEEE754_sp;
  castingIEEE754_sp.i = (s2<<16)|s1;
  return castingIEEE754_sp.f;
}

float
toFloat(unsigned int i1)
{
  union IEEE754_single_precision castingIEEE754_sp;
  castingIEEE754_sp.i = i1;
  return castingIEEE754_sp.f;
}


double
toDouble(unsigned char c1, unsigned char c2, 
	 unsigned char c3, unsigned char c4,
	 unsigned char c5, unsigned char c6, 
	 unsigned char c7, unsigned char c8)
{
  // FIXME
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.c[7] = c4;
  castingIEEE754_dp.c[6] = c3;
  castingIEEE754_dp.c[5] = c2;
  castingIEEE754_dp.c[4] = c1;
  castingIEEE754_dp.c[3] = c8;
  castingIEEE754_dp.c[2] = c7;
  castingIEEE754_dp.c[1] = c6;
  castingIEEE754_dp.c[0] = c5;
  return castingIEEE754_dp.d; 
  
}

double
toDouble(unsigned short s1, unsigned short s2, 
	 unsigned short s3, unsigned short s4)
{
  // FIXME
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.s[3] = s2;
  castingIEEE754_dp.s[2] = s1;
  castingIEEE754_dp.s[1] = s4;
  castingIEEE754_dp.s[0] = s3;
  return castingIEEE754_dp.d; 
  
}

double
toDouble(unsigned int i1, unsigned int i2)
{
  // FIXME
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.i[1] = i1;
  castingIEEE754_dp.i[0] = i2;
  return castingIEEE754_dp.d; 
  
}


void
toSequence(float n, unsigned char bytes[4])
{
  union IEEE754_single_precision castingIEEE754_sp;
  castingIEEE754_sp.f = n;
  bytes[3] = (castingIEEE754_sp.i >> 24) & 0xFF;
  bytes[2] = (castingIEEE754_sp.i >> 16) & 0xFF;
  bytes[1] = (castingIEEE754_sp.i >> 8) & 0xFF;
  bytes[0] = castingIEEE754_sp.i & 0xFF;
}

void
toSequence(float n, unsigned short words[2])
{
  union IEEE754_single_precision castingIEEE754_sp;
  castingIEEE754_sp.f = n;
  words[1] = (castingIEEE754_sp.i >> 16) & 0xFFFF;
  words[0] = castingIEEE754_sp.i & 0xFFFF;
}

void
toSequence(float n, unsigned int words[1])
{
  union IEEE754_single_precision castingIEEE754_sp;
  castingIEEE754_sp.f = n;
  words[0] = castingIEEE754_sp.i;
}


void
toSequence(double n, unsigned char bytes[8])
{
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.d = n;
  bytes[3] = (castingIEEE754_dp.ll >> 56) & 0xFF;
  bytes[2] = (castingIEEE754_dp.ll >> 48) & 0xFF;
  bytes[1] = (castingIEEE754_dp.ll >> 40) & 0xFF;
  bytes[0] = (castingIEEE754_dp.ll >> 32) & 0xFF;
  bytes[7] = (castingIEEE754_dp.ll >> 24) & 0xFF;
  bytes[6] = (castingIEEE754_dp.ll >> 16) & 0xFF;
  bytes[5] = (castingIEEE754_dp.ll >> 8) & 0xFF;
  bytes[4] = castingIEEE754_dp.ll & 0xFF;
}

void
toSequence(double n, unsigned short words[4])
{
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.d = n;
  words[1] = (castingIEEE754_dp.ll >> 48) & 0xFFFF;
  words[0] = (castingIEEE754_dp.ll >> 32) & 0xFFFF;
  words[3] = (castingIEEE754_dp.ll >> 16) & 0xFFFF;
  words[2] = castingIEEE754_dp.ll & 0xFFFF;
}

void
toSequence(double n, unsigned int words[2])
{
  union IEEE754_double_precision castingIEEE754_dp;
  castingIEEE754_dp.d = n;
  words[0] = (castingIEEE754_dp.ll >> 32) & 0xFFFFFFFF;
  words[1] = castingIEEE754_dp.ll & 0xFFFFFFFF;
}


