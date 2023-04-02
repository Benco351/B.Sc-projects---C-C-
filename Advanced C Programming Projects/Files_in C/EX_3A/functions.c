#include "Header.h"

//check if an allocation succeed
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
// check if a file open correctly or not
void checkFile(FILE* f)
{
	if (f == NULL)
	{
		perror("Opening file failed!\n");
		exit(EXIT_FAILURE);
	}
}
 
char* index_file(int fileSize,char* name)
{
	char* ind_file = (char*)malloc(sizeof(char) * fileSize);
	checkMemoryAllocation(ind_file);
	strcpy(ind_file, name);
	strcat(ind_file, ".ind");
	return ind_file;

}
void installize(STUDENT*** students, int LogicSizes[MAXIMUM_AVERAGE][2])
{
	for (int i = 0; i < MAXIMUM_AVERAGE; i++)
	{
		students[i] = NULL;
		LogicSizes[i][1] = 1;
	}
}
void reallocationAfter(STUDENT*** students, int LogicSizes[MAXIMUM_AVERAGE][2])
{
	for (int i = 0; i < MAXIMUM_AVERAGE; i++)
	{
		if (LogicSizes[i][0] < LogicSizes[i][1] && students[i] != NULL)
		{
			students[i] = (STUDENT**)realloc(students[i], sizeof(STUDENT*) * LogicSizes[i][0]);
			checkMemoryAllocation(students[i]);
		}
	}
}
void ind_creator(U_longInt* indexes, STUDENT*** students,int size, int LogicSizes[MAXIMUM_AVERAGE][2],char* ind_File)
{
	U_longInt* tmp = (U_longInt*)calloc(sizeof(U_longInt), size);
	checkMemoryAllocation(tmp);
	int temp_ind = 0;
	for (int i = 0; i < MAXIMUM_AVERAGE; i++)
	{
		if (students[i] != NULL)
		{
			if (LogicSizes[i][0] > 1 )
			{
				for (int j = 0; j < LogicSizes[i][0]; j++)
				{
					tmp[temp_ind++] = indexes[students[i][j]->index];
				}
			}
			else
			{
				tmp[temp_ind++] = indexes[students[i][0]->index];
			}

		}
	}
	
	FILE* ind_Bstu = fopen(ind_File, "wb");
	checkFile(ind_Bstu);
	for (short int i = 0; i < size; i++)
	{
		fwrite(&tmp[i], sizeof(U_longInt), 1, ind_Bstu);
	}
	fclose(ind_Bstu);
	free(tmp);
}
//build the ind file from the main file. count sort implementaion all in one ! complexity O(n)
void build(char* fileName)
{
	char* ind_File = index_file(strlen(fileName) + 1,fileName);

	FILE* Bstu = fopen(fileName, "rb");
	checkFile(Bstu);
	long int fSize = fileSize(Bstu);
	short int n, i = 0, len;
	fread(&n, sizeof(short int), 1, Bstu);
	STUDENT*** students = (STUDENT***)calloc(sizeof(STUDENT**) , MAXIMUM_AVERAGE);
	checkMemoryAllocation(students);
	U_longInt* indexes = (U_longInt*)malloc(sizeof(U_longInt) * n);
	checkMemoryAllocation(indexes);
	int LogicSizes[MAXIMUM_AVERAGE][2] = { 0 };
	installize(students, LogicSizes);

	int average;
	while (ftell(Bstu) < fSize && i < n)
	{
		short int curr = (short int)ftell(Bstu);
		fread(&len, sizeof(short int), 1, Bstu);
		fseek(Bstu, sizeof(char)* len, SEEK_CUR);
		fread(&average, sizeof(int), 1, Bstu);
		if (LogicSizes[average][0] >LogicSizes[average][1] )
		{
			LogicSizes[average][1] *= 2;
			students[average] = (STUDENT**)realloc(students[average],sizeof(STUDENT*) * LogicSizes[average][1]);
			checkMemoryAllocation(students[average]);
			
		}
		else
		{
			students[average] = (STUDENT**)malloc(sizeof(STUDENT*) * LogicSizes[average][1]);
			checkMemoryAllocation(students[average]);
		
		}
		students[average][LogicSizes[average][0]] = (STUDENT*)malloc(sizeof(STUDENT));
		checkMemoryAllocation(students[average]);
		students[average][LogicSizes[average][0]]->average = average;
		fseek(Bstu, curr + sizeof(short int), SEEK_SET);
		students[average][LogicSizes[average][0]]->name = (char*)malloc(sizeof(char) * len+1);
		checkMemoryAllocation(students[average][LogicSizes[average][0]]->name);
		students[average][LogicSizes[average][0]]->index = i;
		indexes[i] = curr;
		fread(students[average][LogicSizes[average][0]]->name, sizeof(char), len, Bstu);
		students[average][LogicSizes[average][0]]->name[len] = '\0';
		fseek(Bstu, sizeof(int), SEEK_CUR);
		LogicSizes[average][0] += 1;
		i++;
	}
	fclose(Bstu);
	//logic->physi
	reallocationAfter(students, LogicSizes);
	ind_creator(indexes, students, n, LogicSizes, ind_File); // create the indexes file
	free(indexes);
	freeArr(students, LogicSizes);
	free(students);
}
// free all the array content
void freeArr(STUDENT*** arr,int LogicSizes[MAXIMUM_AVERAGE][2])
{
	for (int i = 0; i < MAXIMUM_AVERAGE;i++)
	{
		if (arr[i] != NULL)
		{
			if (LogicSizes[i][0] > 1)
			{
				for (int j = 0; j < LogicSizes[i][0]; j++)
				{
					free(arr[i][j]->name);
				}
			}
			else
			{
				free(arr[i][0]->name);
			}
			free(arr[i]);
		}
	}
}
