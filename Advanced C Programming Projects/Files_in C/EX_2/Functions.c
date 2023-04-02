#include "Header.h"
// build the file 
void build(char* File1name, char* File2name)
{
	unsigned short int PhysicSize = 1, LogicSize = 0;
	Employee** company = (Employee**)malloc(PhysicSize * sizeof(Employee*));
	checkMemoryAllocation(company);
    FILE* Read_Update_File = fopen(File1name, "rb");
	FILE* Update_From_File = fopen(File2name, "rb");
	checkFile(Update_From_File);
	checkFile(Read_Update_File);
	long int Fsize_Read_update = fileSize(Read_Update_File);
	long int Fsize_Update_from = fileSize(Update_From_File);
	float Raise;
	while (ftell(Read_Update_File) < Fsize_Read_update 
		&& ftell(Update_From_File) < Fsize_Update_from)
	{
		if (LogicSize >= PhysicSize)
		{
			PhysicSize *= 2;
			company = (Employee**)realloc(company, PhysicSize * sizeof(Employee*));
			company[LogicSize] = (Employee*)malloc(sizeof(Employee));
			checkMemoryAllocation(company[LogicSize]);	
		}
		else
		{
			company[LogicSize] = (Employee*)malloc(sizeof(Employee));
			checkMemoryAllocation(company[LogicSize]);
		}
		fread(&company[LogicSize]->name_length, sizeof(int), 1, Read_Update_File);
		company[LogicSize]->name = (char*)malloc((company[LogicSize]->name_length) +1*sizeof(char));
		checkMemoryAllocation(company);
		company[LogicSize]->name[company[LogicSize]->name_length] = '\0';
		fread(company[LogicSize]->name, sizeof(char), company[LogicSize]->name_length, Read_Update_File);	
		fread(&Raise, sizeof(float), 1, Update_From_File);
		fread(&company[LogicSize]->salary, sizeof(float), 1, Read_Update_File);
		float updated = company[LogicSize]->salary + Raise;
		company[LogicSize]->salary = updated;
	
		LogicSize++;
	}
	fclose(Update_From_File);
	if (LogicSize < PhysicSize)
	{
		company = (Employee**)realloc(company, LogicSize * sizeof(Employee*));
	}
	heapSort(company, LogicSize);
	fclose(Read_Update_File);
	updateFile(File1name, company, LogicSize);
	freeInside(company, LogicSize);
	free(company);

}
//free the array of employees
void freeInside(Employee** company, unsigned short int LogicSize)
{
	for (unsigned short int i = 0; i < LogicSize; i++)
	{
		free(company[i]->name);
		free(company[i]);
	}
}
//insert the sorted data into a a new file
void updateFile(char* fp, Employee** company, unsigned short int logicSize)
{
	FILE* Read_Update_File = fopen(fp, "wb+");
	checkFile(Read_Update_File);

	for (unsigned short int i = 0; i < logicSize; i++)
	{
		fwrite(&company[i]->name_length, sizeof(int), 1, Read_Update_File);
		fwrite(company[i]->name, company[i]->name_length, 1, Read_Update_File);
		fwrite(&company[i]->salary, sizeof(float), 1, Read_Update_File);
	}
	fclose(Read_Update_File);
}
//swap the employee elements using a temp
void swap(Employee** first, Employee** last)
{
	Employee* tmp = *first;
	*first = *last;
	*last = tmp;
}
//heapify utillity function of heap sort
void heapify(Employee** output, int size, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < size && output[l]->salary < output[largest]->salary)
		largest = l;
	if (r < size && output[r]->salary < output[largest]->salary)
		largest = r;
	if (largest != i)
	{
		swap(&output[i], &output[largest]);
		heapify(output, size, largest);
	}
}
// heap sort algorithm , sorting an array by the salary
void heapSort(Employee** output, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(output, size, i);
	for (int i = size - 1; i > 0; i--)
	{
		swap(&output[0], &output[i]);
		heapify(output, i, 0);
	}
}
// get the file size in BYTES
long int fileSize(FILE* file)
{
	long int res;

	fseek(file, 0, SEEK_END);
	res = ftell(file);
	fseek(file, 0, SEEK_SET);

	return res;
}
// check if a file open correctly
void checkFile(FILE* f)
{
	if (f == NULL)
	{
		perror("Opening file failed!\n");
		exit(EXIT_FAILURE);
	}
}
// check the memory allocation succeed
void checkMemoryAllocation(void* ptr)
{
	if (ptr == NULL)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
}