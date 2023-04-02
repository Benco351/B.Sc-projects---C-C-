#ifndef HEADER_H
#define HEADER_H
	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	typedef unsigned char BYTE;
	int* filter(int* Numbers, int size, BYTE* pred,
		int* new_size);
	char IFBitIset(BYTE byte, int i);
	int* xorFilter(int* Numbers, int size, unsigned char* pred1,
		unsigned char* pred2, int* new_size);

#endif // !HEADER_H

