#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef short int SI;
void build(char* fileName, int size);
long int fileSize(FILE* file);
void checkMemoryAllocation(void* ptr);
void checkFile(FILE* f);
char* ReAllocate(char** output, int index, int num);
void heapSort(char** output, int size);
void heapify(char** output, int size, int i);
void swap(char** first, char** last);
void createTextoutput(char** output, int size, char* fileName);
void freeOutput(char** output, int size);