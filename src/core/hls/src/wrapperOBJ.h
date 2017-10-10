#ifndef WRAPPEROBJ_H
#define WRAPPEROBJ_H


//#include <ap_int.h>
#include <hls_stream.h>

#include "vector_norm.h"

const int OBJ_BUS_WIDTH_BYTES = 4; //int

static unsigned char ID_OBJ=1;



///////////////////////////////////////////////////////////////////////
//                 Function:   scale2
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_scale2 = 1;
static unsigned char ID_OBJ_scale2 = 1;

const int OBJ_SCALE2_READ_SIZE_BYTES = 4; //int
const int OBJ_SCALE2_WRITE_SIZE_BYTES = 4; //int

struct PARAM_OBJ_scale2{
  float sum;    
  // here padding if its necessary
}__attribute__((packed));


struct RETURN_OBJ_scale2{
  float _return;
  // here padding if its necessary
}__attribute__((packed));

static struct PARAM_OBJ_scale2  args_OBJ_scale2;
static struct RETURN_OBJ_scale2  ret_OBJ_scale2;

void testing_OBJ_scale2(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst);
void readParameters_OBJ_scale2(hls::stream<unsigned int> &src);
void writeReturn_OBJ_scale2(hls::stream<unsigned int> &dst);
//////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                 Function:   sum_hist_pow
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_sum_hist_pow = 2;
static unsigned char ID_OBJ_sum_hist_pow = 2;

const int OBJ_SUM_HIST_POW_READ_SIZE_BYTES = 4; //int
const int OBJ_SUM_HIST_POW_WRITE_SIZE_BYTES = 4; //int

struct PARAM_OBJ_sum_hist_pow{
  float histIN[HIST_SIZE];    
  // here padding if its necessary
}__attribute__((packed));


struct RETURN_OBJ_sum_hist_pow{
  float _return;
  // here padding if its necessary
}__attribute__((packed));

static struct PARAM_OBJ_sum_hist_pow  args_OBJ_sum_hist_pow;
static struct RETURN_OBJ_sum_hist_pow  ret_OBJ_sum_hist_pow;

void testing_OBJ_sum_hist_pow(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst);
void readParameters_OBJ_sum_hist_pow(hls::stream<unsigned int> &src);
void writeReturn_OBJ_sum_hist_pow(hls::stream<unsigned int> &dst);
//////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                 Function:   mult_hist_scale
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_mult_hist_scale = 3;
static unsigned char ID_OBJ_mult_hist_scale = 3;

const int OBJ_MULT_HIST_SCALE_READ_SIZE_BYTES = 4; //int
const int OBJ_MULT_HIST_SCALE_WRITE_SIZE_BYTES = 4; //int

struct PARAM_OBJ_mult_hist_scale{
  float histAUX[HIST_SIZE];  
  float scale;    
  // here padding if its necessary
}__attribute__((packed));


struct RETURN_OBJ_mult_hist_scale{
  float histOUT[HIST_SIZE];  
  // here padding if its necessary
}__attribute__((packed));

static struct PARAM_OBJ_mult_hist_scale  args_OBJ_mult_hist_scale;
static struct RETURN_OBJ_mult_hist_scale  ret_OBJ_mult_hist_scale;

void testing_OBJ_mult_hist_scale(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst);
void readParameters_OBJ_mult_hist_scale(hls::stream<unsigned int> &src);
void writeReturn_OBJ_mult_hist_scale(hls::stream<unsigned int> &dst);
//////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                 Function:   l2norm
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_l2norm = 7;
/* static unsigned char ID_OBJ_l2norm = 7; */

/* const int OBJ_L2NORM_READ_SIZE_BYTES = 4; //int */
/* const int OBJ_L2NORM_WRITE_SIZE_BYTES = 4; //int */

/* struct PARAM_OBJ_l2norm{ */
/*   float histIN[HIST_SIZE];     */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */


/* struct RETURN_OBJ_l2norm{ */
/*   float histOUT[HIST_SIZE];   */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */

/* static struct PARAM_OBJ_l2norm  args_OBJ_l2norm; */
/* static struct RETURN_OBJ_l2norm  ret_OBJ_l2norm; */

/* void testing_OBJ_l2norm(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst); */
/* void readParameters_OBJ_l2norm(hls::stream<unsigned int> &src); */
/* void writeReturn_OBJ_l2norm(hls::stream<unsigned int> &dst); */
//////////////////////////////////////////////////////////////////////



#endif
