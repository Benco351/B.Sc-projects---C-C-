#include "Header.h"
//Create an integer array from the user and return the logicsize
int* getIntArr(int* intSize)
{

	(void)scanf("%d", intSize);
	int* arr = NULL;
	arr = (int*)DynamicAllocation(arr, sizeof(int), (*intSize), MALLOC);
	for (int i = 0; i < *intSize; i++)
	{
        (void)scanf("%d", &arr[i]);
	}
	return arr;
}
void CheckMem(void* mem)
{
    if (mem == NULL)
    {
        exit(EXIT_FAILURE);
    }

}
//create a strings array from the user 
char** getStringArr(int* str_Array_Size)
{
    int StartSize = 1, LogicSize = 0, index = 0;
    (void)scanf("%d", str_Array_Size);
    char** str_array = NULL;
    char* TempArr = NULL;
    str_array = (char**)DynamicAllocation(str_array, sizeof(char*), (*str_Array_Size), MALLOC);
    TempArr = (char*)DynamicAllocation(TempArr, sizeof(char), StartSize + 1, MALLOC);

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
                TempArr = (char*)DynamicAllocation(TempArr, sizeof(char), StartSize,
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
// function that reset the specific elements 
char* resetElements(int* physic, int* logic, int* index, char* TempArr)
{
    *physic = 1;
    *logic = 0;
    *index = 0;
    free(TempArr);
    TempArr = NULL;
    TempArr = (char*)DynamicAllocation(TempArr, sizeof(char), (*physic) + 1, MALLOC);
    return TempArr;
}
//return the chosed integer if found in the array of strings
int stringBinSearch(char** stringArr, int stringSize, char stringToFind[100])
{
    return binSearch(stringArr, stringSize, sizeof(char*), &stringToFind, compareStrings);
}
int compareStrings(void* elem1, void* elem2)
{
    char* num1 = *(char**)elem1;
    char* num2 = *(char**)elem2;
    return strcmp(num1,num2);
}
//return the chosed integer if found in the array of integers
int intBinSearch(int* arr, int intSize, int intToFind)
{
    return binSearch(arr, intSize, sizeof(int), &intToFind, compareInt);
}

int compareInt(void* elem1, void* elem2)
{
    int num1 = *(int*)elem1;
    int num2 = *(int*)elem2;
    return num1 - num2;
}

//Generic binsearch
int binSearch(void* Arr, int Size, int ElemSize, void* Item, int (*compare)(void*, void*))
{
    bool found = false;
    int left = 0;
    int right = Size - 1;
    while (left <= right && !found)
    {
        int place = ((left + right) / 2);
        int res = compare((BYTE*)Item, (BYTE*)Arr + place * ElemSize);
        if (res == 0) found = true; else if (res > 0) left = place + 1; else right = place - 1;
    }
    return (int)found;
}


//Dynamic allocation function  for every ptr
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
//free all the malloced memories
void freeMemory(int* intArr, int intSize, char** stringArr, int stringSize)
{
    free(intArr);
    for (int i = 0; i < stringSize; i++)
    {
        free(stringArr[i]);
    }
    free(stringArr);
}