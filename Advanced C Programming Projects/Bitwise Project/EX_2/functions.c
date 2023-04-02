#include "Header.h"
//filter the int array according to the pred array of bytes position in of the specific position of the byte 
int* filter(int* Numbers, int size, BYTE* pred,
	int* new_size)
{
	int sizeofPred = (size / 8) * sizeof(char);
	int* result = (int*)malloc(sizeof(int) * size);
	if (result == NULL)
		exit(EXIT_FAILURE);
	int index = 0, k = 0, jump = 0, j = 0;
	while (k < sizeofPred)
	{
		for (j = 0; j < 7; j++)
		{
			if (IFBitIset(pred[k], j) == '1')
			{
				result[index++] = Numbers[j+jump];
			}
		}
		jump += 8;
		k++;
	}
	if (index < size)
	{
		result = (int*)realloc(result, index * sizeof(int));
		if (result == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	*new_size = index;
	return result;
}
//XOR filter for the int numbers array
int* xorFilter(int* Numbers, int size, unsigned char* pred1,
	unsigned char* pred2, int* new_size)
{
	int sizeofPred = (size / 8) * sizeof(char);
	int* result = (int*)malloc(sizeof(int) * size);
	if (result == NULL)
		exit(EXIT_FAILURE);
	int index = 0, k = 0, jump = 0, j = 0;
	while (k < sizeofPred)
	{
		for (j = 0; j < 7; j++)
		{
			if ((IFBitIset(pred1[k], j) == '1' && IFBitIset(pred2[k], j) == '0')
				|| (IFBitIset(pred1[k], j) == '0' && IFBitIset(pred2[k], j) == '1'))
			{
				result[index++] = Numbers[j + jump];
			}
		}
		jump += 8;
		k++;
	}
	if (index < size)
	{
		result = (int*)realloc(result, index * sizeof(int));
		if (result == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	*new_size = index;
	return result;
}
//return if a byte is on/off
char IFBitIset(BYTE byte, int i)
{
	BYTE mask = 1<<i;
	if (byte & mask)
	{
		return '1';
	}
	return '0';
}