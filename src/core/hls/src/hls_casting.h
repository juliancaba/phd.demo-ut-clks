#ifndef HLS_CASTING_H
#define HLS_CASTING_H



// Enteros
short toShort(unsigned char c1, unsigned char c2);

int
toInt(unsigned char c1, unsigned char c2, 
      unsigned char c3, unsigned char c4);
int
toInt(unsigned short s1, unsigned short s2);

long long
toLongLong(unsigned char c1, unsigned char c2, 
	   unsigned char c3, unsigned char c4,
	   unsigned char c5, unsigned char c6, 
	   unsigned char c7, unsigned char c8);
long long
toLongLong(unsigned short s1, unsigned short s2, 
	   unsigned short s3, unsigned short s4);
long long
toLongLong(unsigned int i1, unsigned int i2);


void
toSequence(short n, unsigned char bytes[2]);

void
toSequence(int n, unsigned char bytes[4]);
void
toSequence(int n, unsigned short words[2]);

void
toSequence(long long n, unsigned char bytes[8]);
void
toSequence(long long n, unsigned short words[4]);
void
toSequence(long long n, unsigned int words[2]);



// Dobles
float
toFloat(unsigned char c1, unsigned char c2, 
	unsigned char c3, unsigned char c4);
float
toFloat(unsigned short s1, unsigned short s2);
float
toFloat(unsigned int i1);

void
toSequence(float n, unsigned char bytes[4]);
void
toSequence(float n, unsigned short words[2]);
void
toSequence(float n, unsigned int words[1]);

double
toDouble(unsigned char c1, unsigned char c2, 
	 unsigned char c3, unsigned char c4,
	 unsigned char c5, unsigned char c6, 
	 unsigned char c7, unsigned char c8);
double
toDouble(unsigned short s1, unsigned short s2, 
	 unsigned short s3, unsigned short s4);
double
toDouble(unsigned int i1, unsigned int i2);

void
toSequence(double n, unsigned char bytes[8]);
void
toSequence(double n, unsigned short words[4]);
void
toSequence(double n, unsigned int words[2]);

#endif
