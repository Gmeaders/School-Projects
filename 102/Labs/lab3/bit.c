#include "lab3.h"

unsigned short my_htons( unsigned short h_format){
	//want to essentially switch the order
	//Ex: originial (10) is 0000 0000 0000 1010
	//We want this to end up becoming 0000 1010 0000 0000.
	h_format = h_format >> 8;
	return h_format;
}

// 32768 16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1

short count_ones(unsigned int input){
	//this is actually 2147483648, so the 1 is in the furthermost left spot, and everything else is 0
	unsigned int mask = 0x80000000;
	//store a count starting at 0
	unsigned int i = 0;
	//compare the input and the mask. 
	//if both are 1, increase count
	//shift the mask to compare the next bit
	//keep going until mask < 0
	while(mask > 0)
	{
		if((input & mask) > 0)
		{
			i++;
		}
	mask >>= 1;	
	//return the count
	}
	return i;
	
}
