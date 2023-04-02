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
// create the index_file name 
char* index_file(int fileSize, char* name)
{
	char* ind_file = (char*)malloc(sizeof(char) * fileSize);
	checkMemoryAllocation(ind_file);
	strcpy(ind_file, name);
	strcat(ind_file, ".ind");
	return ind_file;

}
// installize the students array and the logic sizes in correlation
void installize(STUDENT*** students, int LogicSizes[MAXIMUM_AVERAGE][2])
{
	for (int i = 0; i < MAXIMUM_AVERAGE; i++)
	{
		students[i] = NULL;
		LogicSizes[i][1] = 1;
	}
}
//realloc all the sub arrays with physic logic
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
//function that create the index file 
void ind_creator(U_longInt* indexes, STUDENT*** students, int size, int LogicSizes[MAXIMUM_AVERAGE][2], char* ind_File)
{
	U_longInt* tmp = (U_longInt*)calloc(sizeof(U_longInt), size);
	checkMemoryAllocation(tmp);
	int temp_ind = 0;
	for (int i = 0; i < MAXIMUM_AVERAGE; i++)
	{
		if (students[i] != NULL)
		{
			if (LogicSizes[i][0] > 1)
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
	char* ind_File = index_file(strlen(fileName) + 1, fileName);

	FILE* Bstu = fopen(fileName, "rb");
	checkFile(Bstu);
	long int fSize = fileSize(Bstu);
	short int n, i = 0, len;
	fread(&n, sizeof(short int), 1, Bstu);
	STUDENT*** students = (STUDENT***)calloc(sizeof(STUDENT**), MAXIMUM_AVERAGE);
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
		fseek(Bstu, sizeof(char) * len, SEEK_CUR);
		fread(&average, sizeof(int), 1, Bstu);
		if (LogicSizes[average][0] > LogicSizes[average][1])
		{
			LogicSizes[average][1] *= 2;
			students[average] = (STUDENT**)realloc(students[average], sizeof(STUDENT*) * LogicSizes[average][1]);
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
		students[average][LogicSizes[average][0]]->name = (char*)malloc(sizeof(char) * len + 1);
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
void freeArr(STUDENT*** arr, int LogicSizes[MAXIMUM_AVERAGE][2])
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
//question 3b, return all the students with the exact average
char** findAverageGrade(char* database, int avgGrade, int* resSize)
{
	char* file_ind = index_file(strlen(database) + 1, database);
	FILE* Bstu = fopen(database, "rb");
	checkFile(Bstu);
	FILE* ind_stu = fopen(file_ind, "rb");
	checkFile(ind_stu);

	short int n, i = 0,j=0, len;
	long int fSize = fileSize(Bstu);
	long int f_ind_size = fileSize(ind_stu);
	fread(&n, sizeof(short int), 1, Bstu);
	STUDENT* students = (STUDENT*)malloc(sizeof(STUDENT)*n);
	checkMemoryAllocation(students);

	U_longInt* indexes = (U_longInt*)calloc(sizeof(U_longInt) ,n);
	checkMemoryAllocation(indexes);
	*resSize = 0;
	while (ftell(ind_stu) < f_ind_size && j < n)
	{
		fread(&indexes[j], sizeof(U_longInt), 1,ind_stu);
		j++;
	}
	fclose(ind_stu);

	while ( i < n)
	{	
		fseek(Bstu, indexes[i], SEEK_SET);
		fread(&len, sizeof(short int), 1, Bstu);
		students[i].name = (char*)malloc(sizeof(char) * len + 1);
		checkMemoryAllocation(students[i].name);
		fread(students[i].name, sizeof(char), len, Bstu);
		students[i].name[len] = '\0';
		fread(&students[i].average, sizeof(int), 1, Bstu);
		i++;
	}
	
	int physicalsize = 1, logicsize = 0,index = 0;
	char** names = (char**)malloc(sizeof(char*) * physicalsize);
	checkMemoryAllocation(names);
	for (short int i = 0;i < n;i++)
	{
		if (logicsize > physicalsize)
		{
			physicalsize *= 2;
			names = (char**)realloc(names, physicalsize * sizeof(char*));
			checkMemoryAllocation(names);
		}
		if (students[i].average == avgGrade)
		{
			size_t size = strlen(students[i].name);
			names[index] = (char*)malloc(sizeof(char) * size + 1);
			checkMemoryAllocation(names[index]);
			strcpy(names[index], students[i].name);
			names[index][size] = '\0';
			*resSize += 1;
		}
		logicsize++;
	}
	if (logicsize < physicalsize)
	{
		names = (char**)realloc(names, logicsize * sizeof(char*));
		checkMemoryAllocation(names);
	}
	if (*resSize == 0)
	{
		return NULL;
	}
	free(indexes);
	for (int i = 0;i < n;i++)
	{
		free(students[i].name);
	}
	free(students);
	fclose(Bstu);
	return names;
}