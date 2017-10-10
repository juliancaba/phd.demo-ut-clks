// -*- coding: utf-8; mode: c++; tab-width: 4 -*-

#include "vector_norm.h"
#include <cmath>

#include "hls_math.h"



float
sum_hist_pow(float histIN[HIST_SIZE])
{
  float sum = 0.f;
  float inAUX;

  inAUX = histIN[0];
 loop1:for(int i = 0; i != HIST_SIZE; i++){
	sum += inAUX*inAUX;	  
	//	histAUX_1[i] = inAUX;
    if (i < HIST_SIZE-1)
      inAUX = histIN[i+1];
  }
  return sum;
}


float
scale2(float sum)
{
#ifndef POSIX
  return hls::recipf(sqrtf(sum)+1.6f);
#else
  return 1.f/(sqrtf(sum)+1.6f);
#endif
}



void
mult_hist_scale(float histAUX[HIST_SIZE], float scale, float histOUT[HIST_SIZE])
{
 loop2:for(int i = 0; i != HIST_SIZE; i++)
    histOUT[i] = histAUX[i]*scale;
}

