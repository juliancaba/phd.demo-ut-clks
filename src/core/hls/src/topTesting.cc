#include "topTesting.h"
#include "wrapperOBJ.h"


void
forward_OBJ(hls::stream<unsigned int> &src, short size)
{
  short it=0;
  while(it != size){
    src.read();
    it += 1;
  }
}


void
buildResponse_OBJ(hls::stream<unsigned int> &dst,
		  unsigned short objID, unsigned short size,
		  unsigned char flags)
{
  int words32;

  words32 = (header_OBJ.cb<<16) | (header_OBJ.methodID<<8) | flags;
  dst.write(words32);
  if(flags & FLAG_HAS_PAYLOAD){
    words32 = (objID<<16) | size;
    dst.write(words32);
    while (!bufferRESP_OBJ.empty())
      dst.write(bufferRESP_OBJ.read());
  }
}


void
getRequestHead_OBJ(hls::stream<unsigned int> &src)
{
  int words32[2];

  for(int it=0; it != 2; it++)
    words32[it] = src.read();
  //byteHeader[it].words32 = bufferIN.read();

  header_OBJ.nodeID = (words32[0] >> 24) & 0xFF;
  header_OBJ.objectID = (words32[0] >> 16) & 0xFF;
  header_OBJ.methodID = (words32[0] >> 8) & 0xFF;
  header_OBJ.flags = words32[0] & 0xFF;
  header_OBJ.cb = (words32[1] >> 16) & 0xFFFF;
  header_OBJ.size = words32[1] & 0xFFFF;
}


void
topTesting(hls::stream<unsigned int> din, hls::stream<unsigned int> dout)
{
#pragma HLS STREAM variable=bufferRESP_OBJ depth=32
  
  getRequestHead_OBJ(din);

  if (ID_OBJ == header_OBJ.objectID || BROADCAST == header_OBJ.objectID)
    //  if (ID_add == header.methodID_flags){
    if (ID_OBJ_scale2 == header_OBJ.methodID){
      //      buildResponseHead(bufferOUT);
      testing_OBJ_scale2(din, bufferRESP_OBJ);
      buildResponse_OBJ(dout, ID_OBJ, sizeof(ret_OBJ_scale2)/OBJ_BUS_WIDTH_BYTES,
		    FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_OBJ_sum_hist_pow == header_OBJ.methodID){
      testing_OBJ_sum_hist_pow(din, bufferRESP_OBJ);
      buildResponse_OBJ(dout, ID_OBJ, sizeof(ret_OBJ_sum_hist_pow)/OBJ_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_OBJ_mult_hist_scale == header_OBJ.methodID){
      testing_OBJ_mult_hist_scale(din, bufferRESP_OBJ);
      buildResponse_OBJ(dout, ID_OBJ, sizeof(ret_OBJ_mult_hist_scale)/OBJ_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else{
      forward_OBJ(din, header_OBJ.size);
      buildResponse_OBJ(dout, ID_OBJ, 0, 
			FLAG_RESPONSE|FLAG_FAIL);
    }
  else{
    forward_OBJ(din, header_OBJ.size);
    buildResponse_OBJ(dout, NULL_OBJ, 0, 
		      FLAG_RESPONSE|FLAG_FAIL);
  }
}

