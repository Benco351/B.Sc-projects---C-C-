#include "Header.h"

void checkMemoryAllocation(void* ptr)
{
	if (ptr == NULL)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
}
//return the amount of bits in the file
long int fileSize(FILE* file)
{
	long int res;

	fseek(file, 0, SEEK_END);
	res = ftell(file);
	fseek(file, 0, SEEK_SET);

	return res;
}

void checkFile(FILE* f)
{
	if (f == NULL)
	{
		perror("Opening file failed!\n");
		exit(EXIT_FAILURE);
	}
}
//read the file and sort the output 
void build(char* fileName, int size)
{
	size_t num;
	char** output = (char**)malloc(size * sizeof(char*));
	checkMemoryAllocation(output);
	
	FILE* B = fopen(fileName, "rb");
	checkFile(B);
	long int Fsize = fileSize(B);
	int i = 0;
	while( i < size && ftell(B) < Fsize)
	{
		fread(&num, sizeof(int), 1, B);
		output[i] = (char*)malloc((num + 1) * sizeof(char));
		checkMemoryAllocation(output[i]);
		output[i][num] = '\0';
		fread(output[i], sizeof(char), num, B);
		output[i] = ReAllocate(output, i, num);
		i++;
	}
	heapSort(output, size);
	fclose(B);
	createTextoutput(output, size, fileName);
	freeOutput(output, size);
	free(output);
}
// free the output buffer
void freeOutput(char** output, int size)
{
	for(int i = 0; i < size; i++)
	{
		free(output[i]);
	}
}
//insert all the output after sort to a new text file
void createTextoutput(char** output, int size,char*fileName)
{
	strcat(fileName, ".txt");
	FILE* Text_bin = fopen(fileName, "w+");
	checkFile(Text_bin);
	for (int i = 0; i < size; i++)
	{
		fprintf(Text_bin, "%s\n", output[i]);
	}
	fclose(Text_bin);
}
// swap two elements
void swap(char** first, char** last)
{
	char* tmp = *first;
	*first = *last;
	*last = tmp;
}
// heap sort - sort in  lexigoraphic order log(n)
void heapify(char** output, int size, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2;
	if (l < size && strcmp(output[l], output[largest])>0)
		largest = l;
	if (r < size && strcmp(output[r] , output[largest])>0)
		largest = r;
	if (largest != i) 
	{
		swap(&output[i], &output[largest]);
		heapify(output, size, largest);
	}
}
// heap sort main function that calls the recursive function heapify
void heapSort(char** output, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(output, size, i);
	for (int i = size - 1; i > 0; i--) 
	{
		swap(&output[0], &output[i]);
		heapify(output, i, 0);
	}
}
// reallocate the output buffer with the required information.
char* ReAllocate(char** output, int index,int num)
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (output[index][i] >= 'a' && output[index][i] <= 'z')
		{
			output[index][count++] = output[index][i];
		}
	}
	output[index] = (char*)realloc(output[index], count+1);
	output[index][count] = '\0';
	return output[index];
}