#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct employee
{
    int name_length;
    char* name;
    float  salary;
} Employee;

void checkMemoryAllocation(void* ptr);
void checkFile(FILE* f);
long int fileSize(FILE* file);
void build(char* File1name, char* File2name);
void freeInside(Employee** company, unsigned short int LogicSize);
void heapSort(Employee** output, int size);
void heapify(Employee** output, int size, int i);
void updateFile(char* fp, Employee** company, unsigned short int logicSize);