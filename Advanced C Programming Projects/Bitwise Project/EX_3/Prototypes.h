#ifndef PROTOTYPES_H
#define PROTOTYPES_H
    int* getIntArr(int* intSize);
    int* scrambleInt(int* arr, int size, int indArr[100]);
    void* scramble(void* arr, int ElemSize, int n, int* indArr);
    void printIntArr(int* arr, int size);
    char** getStringArr(int* str_Array_Size);
    char** scrambleString(char** stringArr, int stringSize, int indArr[100]);
    void printStringArr(char** scrambleStringArr, int stringSize);
    void freeMemory(int* intArr, int* scrambleIntArr, int intSize, char** stringArr, char** scrambleStringArr, int stringSize);
    char* resetElements(int* physic, int* logic, int* index, char* TempArr);
    void* DynamicAllocation(void* ptr_ptr, size_t elemSize, size_t num_Of_elements, int Format);
    void CheckMem(void* mem);
#endif // 
