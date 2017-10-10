#ifndef TOPTESTING_H
#define TOPTESTING_H

#include "header.h"

#include <hls_stream.h>


static struct headerStruct header_OBJ;

static hls::stream<unsigned int> bufferRESP_OBJ;

void forward_OBJ(hls::stream<unsigned int> &src, short size);

void getRequestHead_OBJ(hls::stream<unsigned int> &src);
void buildResponse_OBJ(hls::stream<unsigned int> &dst,
		       unsigned short objID, unsigned short size, 
		       unsigned char flags);

void topTesting(hls::stream<unsigned int> din,
		hls::stream<unsigned int> dout);

#endif
