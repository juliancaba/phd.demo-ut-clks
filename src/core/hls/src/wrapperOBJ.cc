#include "wrapperOBJ.h"

#include "hls_casting.h"


///////////////////////////////////////////////////////////////////////
//                  Function:   scale2
//////////////////////////////////////////////////////////////////////
union UNION_RET_OBJ_scale2{
  unsigned int words32[sizeof(ret_OBJ_scale2)/sizeof(int)];
  unsigned short words16[sizeof(ret_OBJ_scale2)/sizeof(short)];
  unsigned char words8[sizeof(ret_OBJ_scale2)];
}byteRet_OBJ_scale2;


void
testing_OBJ_scale2(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst)
{
  int ret;
  readParameters_OBJ_scale2(src);
  ret_OBJ_scale2._return = scale2(args_OBJ_scale2.sum);
  writeReturn_OBJ_scale2(dst);
}


void
readParameters_OBJ_scale2(hls::stream<unsigned int> &src)
{ 
  int words32[sizeof(args_OBJ_scale2)/sizeof(int)];

  for(int it=0; it != sizeof(args_OBJ_scale2)/OBJ_BUS_WIDTH_BYTES; it++)
    words32[it] = src.read();
  
  // Casting
  unsigned int *ptr= (unsigned int*)words32;  
  args_OBJ_scale2.sum = toFloat(*ptr++);
}


void
writeReturn_OBJ_scale2(hls::stream<unsigned int> &dst)
{ 
  short index=0;

  unsigned int ptr_ret[sizeof(ret_OBJ_scale2._return)/OBJ_SCALE2_WRITE_SIZE_BYTES];
  toSequence(ret_OBJ_scale2._return, ptr_ret);
  for(int it=0; it!=sizeof(ptr_ret)/OBJ_SCALE2_WRITE_SIZE_BYTES; it++) 
    byteRet_OBJ_scale2.words32[index++] = ptr_ret[it];

  for(int itReturn=0; itReturn != sizeof(byteRet_OBJ_scale2.words32)/OBJ_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_OBJ_scale2.words32[itReturn]); 
}
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                  Function:   sum_hist_pow
//////////////////////////////////////////////////////////////////////
union UNION_RET_OBJ_sum_hist_pow{
  unsigned int words32[sizeof(ret_OBJ_sum_hist_pow)/sizeof(int)];
  unsigned short words16[sizeof(ret_OBJ_sum_hist_pow)/sizeof(short)];
  unsigned char words8[sizeof(ret_OBJ_sum_hist_pow)];
}byteRet_OBJ_sum_hist_pow;


void
testing_OBJ_sum_hist_pow(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst)
{
  int ret;
  readParameters_OBJ_sum_hist_pow(src);
  ret_OBJ_sum_hist_pow._return = sum_hist_pow(args_OBJ_sum_hist_pow.histIN);
  writeReturn_OBJ_sum_hist_pow(dst);
}


void
readParameters_OBJ_sum_hist_pow(hls::stream<unsigned int> &src)
{ 
  int words32[sizeof(args_OBJ_sum_hist_pow)/sizeof(int)];

  for(int it=0; it != sizeof(args_OBJ_sum_hist_pow)/OBJ_BUS_WIDTH_BYTES; it++)
    words32[it] = src.read();
  
  // Casting
  unsigned int *ptr= (unsigned int*)words32;  
  for(int it=0; it != HIST_SIZE; it++)
    args_OBJ_sum_hist_pow.histIN[it] = toFloat(*ptr++);  
}


void
writeReturn_OBJ_sum_hist_pow(hls::stream<unsigned int> &dst)
{ 
  short index=0;

  unsigned int ptr_ret[sizeof(ret_OBJ_sum_hist_pow._return)/OBJ_SUM_HIST_POW_WRITE_SIZE_BYTES];
  toSequence(ret_OBJ_sum_hist_pow._return, ptr_ret);
  for(int it=0; it!=sizeof(ptr_ret)/OBJ_SUM_HIST_POW_WRITE_SIZE_BYTES; it++) 
    byteRet_OBJ_sum_hist_pow.words32[index++] = ptr_ret[it];

  for(int itReturn=0; itReturn != sizeof(byteRet_OBJ_sum_hist_pow.words32)/OBJ_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_OBJ_sum_hist_pow.words32[itReturn]); 
}
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                  Function:   mult_hist_scale
//////////////////////////////////////////////////////////////////////
union UNION_RET_OBJ_mult_hist_scale{
  unsigned int words32[sizeof(ret_OBJ_mult_hist_scale)/sizeof(int)];
  unsigned short words16[sizeof(ret_OBJ_mult_hist_scale)/sizeof(short)];
  unsigned char words8[sizeof(ret_OBJ_mult_hist_scale)];
}byteRet_OBJ_mult_hist_scale;


void
testing_OBJ_mult_hist_scale(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst)
{
  int ret;
  readParameters_OBJ_mult_hist_scale(src);
  mult_hist_scale(args_OBJ_mult_hist_scale.histAUX, args_OBJ_mult_hist_scale.scale, ret_OBJ_mult_hist_scale.histOUT);
  writeReturn_OBJ_mult_hist_scale(dst);
}


void
readParameters_OBJ_mult_hist_scale(hls::stream<unsigned int> &src)
{ 
  int words32[sizeof(args_OBJ_mult_hist_scale)/sizeof(int)];

  for(int it=0; it != sizeof(args_OBJ_mult_hist_scale)/OBJ_BUS_WIDTH_BYTES; it++)
    words32[it] = src.read();
  
  // Casting
  unsigned int *ptr= (unsigned int*)words32;  
  for(int it=0; it != HIST_SIZE; it++)
    args_OBJ_mult_hist_scale.histAUX[it] = toFloat(*ptr++);

  args_OBJ_mult_hist_scale.scale = toFloat(*ptr++);  
}


void
writeReturn_OBJ_mult_hist_scale(hls::stream<unsigned int> &dst)
{ 
  short index=0;

  unsigned int ptr_histOUT[sizeof(ret_OBJ_mult_hist_scale.histOUT[0])/OBJ_MULT_HIST_SCALE_WRITE_SIZE_BYTES];
  for(int it_histOUT=0; it_histOUT != sizeof(ret_OBJ_mult_hist_scale.histOUT)/sizeof(ret_OBJ_mult_hist_scale.histOUT[0]); it_histOUT++){  
    toSequence(ret_OBJ_mult_hist_scale.histOUT[it_histOUT], ptr_histOUT);
    for(int it=0; it!=sizeof(ret_OBJ_mult_hist_scale.histOUT[0])/OBJ_MULT_HIST_SCALE_WRITE_SIZE_BYTES; it++) 
      byteRet_OBJ_mult_hist_scale.words32[index++] = ptr_histOUT[it];
  }

  for(int itReturn=0; itReturn != sizeof(byteRet_OBJ_mult_hist_scale.words32)/OBJ_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_OBJ_mult_hist_scale.words32[itReturn]); 
}
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                  Function:   l2norm
//////////////////////////////////////////////////////////////////////
// union UNION_RET_OBJ_l2norm{
//   unsigned int words32[sizeof(ret_OBJ_l2norm)/sizeof(int)];
//   unsigned short words16[sizeof(ret_OBJ_l2norm)/sizeof(short)];
//   unsigned char words8[sizeof(ret_OBJ_l2norm)];
// }byteRet_OBJ_l2norm;


// void
// testing_OBJ_l2norm(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst)
// {
//   int ret;
//   readParameters_OBJ_l2norm(src);
//   l2norm(args_OBJ_l2norm.histIN, ret_OBJ_l2norm.histOUT);
//   writeReturn_OBJ_l2norm(dst);
// }


// void
// readParameters_OBJ_l2norm(hls::stream<unsigned int> &src)
// { 
//   int words32[sizeof(args_OBJ_l2norm)/sizeof(int)];

//   for(int it=0; it != sizeof(args_OBJ_l2norm)/OBJ_BUS_WIDTH_BYTES; it++)
//     words32[it] = src.read();
  
//   // Casting
//   unsigned int *ptr= (unsigned int*)words32;  
//   for(int it=0; it != HIST_SIZE; it++)
//     args_OBJ_l2norm.histIN[it] = toFloat(*ptr++);
// }


// void
// writeReturn_OBJ_l2norm(hls::stream<unsigned int> &dst)
// { 
//   short index=0;


//   unsigned int ptr_histOUT[sizeof(ret_OBJ_l2norm.histOUT[0])/OBJ_L2NORM_WRITE_SIZE_BYTES];
//   for(int it_histOUT=0; it_histOUT != sizeof(ret_OBJ_l2norm.histOUT)/sizeof(ret_OBJ_l2norm.histOUT[0]); it_histOUT++){  
//     toSequence(ret_OBJ_l2norm.histOUT[it_histOUT], ptr_histOUT);
//     for(int it=0; it!=sizeof(ret_OBJ_l2norm.histOUT[0])/OBJ_L2NORM_WRITE_SIZE_BYTES; it++) 
//       byteRet_OBJ_l2norm.words32[index++] = ptr_histOUT[it];
//   }

//   for(int itReturn=0; itReturn != sizeof(byteRet_OBJ_l2norm.words32)/4; itReturn++)  
//     dst.write(byteRet_OBJ_l2norm.words32[itReturn]); 
// }
///////////////////////////////////////////////////////////////////////

