#ifndef VECTOR_NORM_H
#define VECTOR_NORM_H

const static short HIST_SIZE=16;

float sum_hist_pow(float histIN[HIST_SIZE]);
float scale2(float sum);
void mult_hist_scale(float histAUX[HIST_SIZE], float scale, float histOUT[HIST_SIZE]);

#endif
