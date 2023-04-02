#ifndef PROTOTYPES_H
#define PROTOTYPES_H
	int* getIntArr(int* intSize);
	void* DynamicAllocation(void* ptr_ptr, size_t elemSize, size_t num_Of_elements, int Format);
	void CheckMem(void* mem);
	char** getStringArr(int* str_Array_Size);
	int compareStrings(void* elem1, void* elem2);
	int compareInt(void* elem1, void* elem2);
	int stringBinSearch(char** stringArr, int stringSize, char stringToFind[100]);
	int intBinSearch(int* arr, int intSize, int intToFind);
	int binSearch(void* Arr, int Size, int ElemSize, void* Item, int (*compare)(void*, void*));
	void freeMemory(int* intArr, int intSize, char** stringArr, int stringSize);
	char* resetElements(int* physic, int* logic, int* index, char* TempArr);
#endif // 