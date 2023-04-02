#include "Header.h"


void main(int argc, char* argv[])
{
    char** records;
    int resSize;
    //build(argv[1]); // question 3a uncomment to check the function.
    records = findAverageGrade(argv[1], 100, &resSize);
    printNames(records, resSize);
    for (int i = 0; i < resSize;i++)
    {
        free(records[i]);
    }
    free(records);
}

void printNames(char** records, int size)
{

    int i;

    printf("The students names are:\n");

    for (i = 0; i < size; i++)
        printf("%s\n", records[i]);

}