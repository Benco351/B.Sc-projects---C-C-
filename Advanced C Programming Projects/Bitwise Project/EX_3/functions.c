#include "Header.h"
//read the integer array from the user 
int* getIntArr(int* intSize)
{

	scanf("%d", intSize);
    int* arr = NULL;
    arr = (int*)DynamicAllocation(arr, sizeof(int), (*intSize), MALLOC);
	for (int i = 0; i < *intSize; i++)
	{
		scanf("%d", &arr[i]);
	}
	return arr;
}
//print a giver strings array
void printStringArr(char** scrambleStringArr, int stringSize)
{
	for (int i = 0; i < stringSize; i++)
	{
		printf("%s\n", scrambleStringArr[i]);
	}
}
//print a given integer array
void printIntArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//read the strings array from the user 
char** getStringArr(int* str_Array_Size)
{
    int StartSize = 1, LogicSize = 0, index = 0;
    (void)scanf("%d", str_Array_Size);
    char** str_array = NULL;
    char* TempArr = NULL;
    str_array = (char**)DynamicAllocation(str_array,sizeof(char*), (*str_Array_Size), MALLOC);
    TempArr = (char*)DynamicAllocation(TempArr,sizeof(char), StartSize + 1, MALLOC);

    (void)getchar();
    char ch = getchar();
    if (ch == '\n')
    {
        free(TempArr);
        TempArr = NULL;
        return NULL;
    }

    for (int i = 0; i < (*str_Array_Size); i++)
    {
        while (ch != '\n' && StartSize > LogicSize)
        {
            if (LogicSize + 1 == StartSize)
            {
                StartSize *= 2;
                TempArr = (char*)DynamicAllocation(TempArr, sizeof(char),StartSize,
                    REALLOC);
            }
            TempArr[index++] = ch;
            LogicSize++;
            ch = getchar();
        }
        TempArr[index] = '\0';
        if (LogicSize < StartSize)
        {
            TempArr = (char*)DynamicAllocation(TempArr, sizeof(char), LogicSize + 1,
                REALLOC);
        }
        str_array[i] = (char*)DynamicAllocation(str_array[i], sizeof(char),
            LogicSize + 1, MALLOC);
        strcpy(str_array[i], TempArr);
        TempArr = resetElements(&StartSize, &LogicSize, &index, TempArr);
        (i + 1 < (*str_Array_Size)) ? ch = getchar() : i++;
    }
    return str_array;
}
void CheckMem(void* mem)
{
    if (mem == NULL)
    {
        exit(EXIT_FAILURE);
    }

}
//GENERIC Dynamic allocation function  for char**
void* DynamicAllocation(void* ptr_ptr, size_t elemSize, size_t num_Of_elements, int Format)
{
    if (Format == REALLOC)
    {
        ptr_ptr = realloc(ptr_ptr, num_Of_elements * elemSize);

        CheckMem(ptr_ptr);
        return ptr_ptr;
    }

    if (Format == MALLOC)
    {
        ptr_ptr = malloc(num_Of_elements * elemSize);
        CheckMem(ptr_ptr);
        return ptr_ptr;
    }

    return NULL;
}
// function that reset the specific elements 
char* resetElements(int* physic, int* logic, int* index, char* TempArr)
{
    *physic = 1;
    *logic = 0;
    *index = 0;
    free(TempArr);
    TempArr = NULL;
    TempArr = (char*)DynamicAllocation(TempArr,sizeof(char), (*physic) + 1, MALLOC);
    return TempArr;
}
//return the scrambled string array
char** scrambleString(char** stringArr, int stringSize, int indArr[100])
{
	return (char**)scramble(stringArr, sizeof(char*), stringSize, indArr);
}
//return the scrambled integer array
int* scrambleInt(int* arr, int size, int indArr[100])
{
	return (int*)scramble(arr, sizeof(int), size, indArr);
}
//Generic function that scramble a given random array 
void* scramble(void* arr, int ElemSize, int n, int* indArr)
{
	BYTE* Converted = (BYTE*)arr;
    BYTE* newArr = NULL;
    newArr = (BYTE*)DynamicAllocation(newArr, ElemSize * sizeof(BYTE), n, MALLOC);
	for (int i = 0; i < n; i++)
	{
		memcpy(newArr + i * ElemSize,Converted+indArr[i]* ElemSize,ElemSize);
	}
	return (void*)newArr;
}
//free the malloced memories
void freeMemory(int* intArr, int* scrambleIntArr, int intSize, char** stringArr, char** scrambleStringArr, int stringSize)
{
	for (int i = 0; i < stringSize; i++)
	{
        free(stringArr[i]);
	}
	free(scrambleStringArr);
   	free(stringArr);
    free(intArr);
	free(scrambleIntArr);
}