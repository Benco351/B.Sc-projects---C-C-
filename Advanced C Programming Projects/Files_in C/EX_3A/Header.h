#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXIMUM_AVERAGE 101
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef unsigned long int U_longInt;
typedef struct student {
	char* name;
	int average;
	int index;
}STUDENT;


void freeArr(STUDENT*** arr, int LogicSizes[MAXIMUM_AVERAGE][2]);
void checkMemoryAllocation(void* ptr);
long int fileSize(FILE* file);
void checkFile(FILE* f);
void build(char* fileName);
void ind_creator(U_longInt* indexes, STUDENT*** students, int size, int LogicSizes[MAXIMUM_AVERAGE][2], char* ind_File);
void reallocationAfter(STUDENT*** students, int LogicSizes[MAXIMUM_AVERAGE][2]);
void installize(STUDENT*** students, int LogicSizes[MAXIMUM_AVERAGE][2]);
char* index_file(int fileSize, char* name);