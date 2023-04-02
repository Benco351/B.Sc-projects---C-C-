#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10 // Static Size of arr 1
#define MAX_INT_SIZE 10 // Max integer number in the arr
#define FUNC_COUNT 9 // Number of non recursive functions in the program
#define EXIT 0 // Exit value represent the end of a prosccess
#define ZERO 0 // Some constant value  for nullify arguments.
#define UNDEFINED -1 // Undefined value
#define DEFAULT 1 // 1 integer to represent a default substract.
// Add your recursive functions declarations here
bool isEven(int num, int dig);
int howManyPaths(int x, int y);
int biggestLowPower(int x, int num);
int partSum(int num);
void intToStr(int num, char s[]);
void fillMaxPrefixesArray(int numbers[], int n,
	int maxPrefixesArray[]);
void getMinToStart(int numbers[], int n);
void combineArrays(int sortedArr1[], int size1,
	int sortedArr2[], int size2);
int countSmaller(int arr[], int start, int end, int num);
// Testing functions
int readArray(int data[], int maxSize);
void printArray(int data[], int size);
void bubbleSort(int arr[], int size);
void swap(int arr[], int i, int j);
void checkQ1();
void checkQ2();
void checkQ3();
void checkQ4();
void checkQ5();
void checkQ6();
void checkQ7();
void checkQ8();
void checkQ9();

/*********** main - don't make any changes here !!! ***************************/
void main()
{
	int funcNum;
	bool exit = false;
	while (!exit)
	{
		printf("Enter the number of function you want to check (1-%d) or %d to exit the program: ", FUNC_COUNT, EXIT);
		scanf("%d", &funcNum);
		
		switch (funcNum)
		{
		case 1:
			checkQ1();
			break;
		case 2:
			checkQ2();
			break;
		case 3:
			checkQ3();
			break;
		case 4:
			checkQ4();
			break;
		case 5:
			checkQ5();
			break;
		case 6:
			checkQ6();
			break;
		case 7:
			checkQ7();
			break;
		case 8:
			checkQ8();
			break;
		case 9:
			checkQ9();
			break;
		case EXIT:
			exit = true;
			break;
		default:
			printf("Invalid choice.\n");
		}
		printf("\n");
	}

}

/***************** Testing functions - don't make any changes here!!! ***************/
void checkQ1()
{
	int num, dig;

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	printf("Enter a digit: ");
	scanf("%d", &dig);
	if (isEven(num, dig))
	{
		printf("%d appears even number of times in %d\n", dig, num);
	}
	else
	{
		printf("%d appears odd number of times in %d\n", dig, num);
	}
}

void checkQ2()
{
	int x, y;

	printf("Enter two non-negative integers: ");
	scanf("%d%d", &x, &y);
	printf("There are %d paths from (0,0) to (%d,%d)\n", howManyPaths(x, y), x, y);
}

void checkQ3()
{
	int x, num;

	printf("Enter two positive integers: ");
	scanf("%d%d", &x, &num);
	printf("The biggest power of %d which is smaller than %d is %d\n", x, num, biggestLowPower(x, num));
}

void checkQ4()
{
	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	printf("The partial sum of %d digits is %d\n", num, partSum(num));
}

void checkQ5()
{
	int num;
	char string[MAX_INT_SIZE + 1];

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	intToStr(num, string);
	printf("The string representing the integer %d is %s\n", num, string);
}

void checkQ6()
{
	int numbers[SIZE];
	int maxPrefixes[SIZE];
	int size;

	size = readArray(numbers, SIZE);
	fillMaxPrefixesArray(numbers, size, maxPrefixes);
	printf("Max prefixes array: ");
	printArray(maxPrefixes, size);
}

void checkQ7()
{
	int numbers[SIZE];
	int size;

	size = readArray(numbers, SIZE);
	getMinToStart(numbers, size);
	printf("The minimal number is: %d\n", numbers[0]);

	// check if all other numbers are still inb array
	bubbleSort(numbers, size);
	printf("The sorted array: ");
	printArray(numbers, size);
}

void checkQ8()
{
	int arr1[SIZE], arr2[2 * SIZE];
	int size1, size2;

	size1 = readArray(arr1, SIZE);
	size2 = readArray(arr2, 2 * SIZE - size1);

	// sort arrays
	bubbleSort(arr1, size1);
	bubbleSort(arr2, size2);

	combineArrays(arr1, size1, arr2, size2);
	printf("The combined sorted array: ");
	printArray(arr2, size1 + size2);
}

void checkQ9()
{
	int numbers[SIZE];
	int size, num;

	// read numbers from user (assumption: numbers are different from each other)
	size = readArray(numbers, SIZE);
	bubbleSort(numbers, size);

	printf("Please enter an integer: ");
	scanf("%d", &num);

	printf("There are %d numbers in array that are smaller than %d\n", countSmaller(numbers, 0, size - 1, num), num);
}

// This function reads a series of integers from user into data array. 
// The function will first ask the user to enter the number of integers he wishes
// to enter to array. If number is bigger than maxSize, then only the first masSize
// numbers will be read.
// The fucntion returns the arrays logical size (number of elements inserted into array).

int readArray(int data[], int maxSize)
{
	int count;
	int i;	// number of elements inserted into array

	printf("How many numbers would you like to enter to array ? (no more than %d) ", maxSize);
	scanf("%d", &count);
	if (count > maxSize)
	{
		count = maxSize;
	}
	printf("Please enter %d integers: ", count);

	for (i = 0; i < count; i++)
	{
		scanf("%d", &data[i]);	// read current input number		
	}

	return count;
}

// This function prints the first size elements of data array (integers).
void printArray(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

// This functions sorts arr in increasing order using bubble sort algorithm
void bubbleSort(int arr[], int size)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
}

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int FindMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i <= size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;

}

/******************************* Recursive functions **************************/
// Add recursive functions implementation here
//****
//*			isEven Function
//*Recursive boolean function - 
//*Return ---> boolean factor that represent either the digit shown even times or odd time in num.
//*	
//*****
bool isEven(int num, int dig)
{

	if (num == ZERO) // num equal to 0
		return true;
	if (dig == num % 10)
		return !isEven(num / 10, dig);
	return isEven(num / 10, dig);
}
//****
//*			howManyPaths Function
//*Recursive int function - 
//*Return ---> All the relative paths from (0,0) dot to (x,y) dots.
//*Assumptions--> Can Move only right and up , one step each time .
//*****
int howManyPaths(int x, int y)
{
	if (x == 0 || y == 0) // (0,0) (1,0) (0,1) all returns 1 path
		return DEFAULT;

	return howManyPaths(x - DEFAULT, y) + howManyPaths(x, y - DEFAULT);// Recursive call + Recursive step
}
//****
//*			biggestLowPower Function
//*Recursive int function - 
//*Return ---> The biggest pow of x that Less or equal to num.
//*Assumptions--> x >= 2.
//*****
int biggestLowPower(int x, int num)
{
	if (num < x)
	{
		return DEFAULT;
	}
	return x * biggestLowPower(x, num / x);// Recursive call + Recursive step
}
//****
//*			partSum Function
//*Recursive int function - 
//*Return ---> Return the sum of all the digit in some number, except the LSD number.
//*Assumptions--> The sum of one digit number is 0.
//*****
int partSum(int num)
{
	if (num < 10)// If one digit number.according to the assumption
	{
		return ZERO;
	}

	return num / 10 % 10 + partSum(num / 10);// Recursive call
}
//****
//*			intToStr Function
//*Recursive void function - 
//*Doing ---> Copy integer number to an array of chars for instance: 234 --> "234".
//*Assumptions--> In the s array of chars there is enough space.
//*****
void intToStr(int num, char s[])
{
	int index = ZERO, tmp = UNDEFINED;
	s[index] = '\0';
	if (num != UNDEFINED)
	{
		tmp = num % 10;
		intToStr(num / 10 == ZERO ? UNDEFINED :num /10, s);//If the next iteration will get a number >10 send the number else send -1 (The Stop Condition).. 
		index = strlen(s);
	}
	if (tmp >= ZERO) {
		s[index++] = tmp + '0';
		s[index] = '\0';
	}
	
}
//****
//*			fillMaxPrefixesArray Function
//*Recursive void function - 
//*Doing ---> To fill the n places in the maxPrefixes.. array so in the (i) place the max{number[0]....numbers[i]} number inserted.
//*Assumptions--> In the maxPrefixesArray array there is enough space.
//*****
void fillMaxPrefixesArray(int numbers[], int n, int maxPrefixesArray[])
{
	int maximum;
	if (n-DEFAULT != ZERO) // stop condition : if the logic size equal to 1
	{

		fillMaxPrefixesArray(numbers, n - DEFAULT, maxPrefixesArray);// Recursive call

	}
	maximum = FindMax(numbers, n-DEFAULT); // find the maximum number between all numbers.
	maxPrefixesArray[n-DEFAULT] = maximum; // [n-1] to avoid overflow.
}
//****
//*			getMinToStart Function
//*Recursive void function - 
//*Doing ---> Take the minimal number from the array to the start.
//*Assumptions--> The order of the other numbers in the array doesnt matter.
//*****
void getMinToStart(int numbers[], int n)
{
	int temp = numbers[ZERO];
	if (n != ZERO) // if there no numbers to run on / Recursive stop
	{
		temp = numbers[n - DEFAULT];
		getMinToStart(numbers, n - DEFAULT); // Recursive call

	}
	if (temp < numbers[ZERO])
	{
		swap(numbers, ZERO, n-DEFAULT);
	}
}
//****
//*			combineArrays Function
//*Recursive void function - 
//*Doing ---> Merge two arrays into one in ascending order .
//*Assumptions--> There is enough place in sortedArr2 to hold the numbers..
//*****
void combineArrays(int sortedArr1[], int size1,
	int sortedArr2[], int size2)
{
	if (size1 != ZERO&& size2!=ZERO) // case there is numbers inside the two arrays 
	{

		if (sortedArr1[size1 - DEFAULT] > sortedArr2[size2 - DEFAULT])
		{
			sortedArr2[size1 + size2-DEFAULT ] = sortedArr1[size1 - DEFAULT];
			combineArrays(sortedArr1, size1 - DEFAULT, sortedArr2, size2);// Recursive call
		}
		if (sortedArr1[size1 - DEFAULT] <= sortedArr2[size2 - DEFAULT])
		{
			sortedArr2[size1 + size2 -DEFAULT ] = sortedArr2[size2 - DEFAULT];
			combineArrays(sortedArr1, size1, sortedArr2, size2-DEFAULT);// Recursive call
		}
	}
	else if(size1 != ZERO && size2 == ZERO) // case SortedArr2 empty.
	{
		
		sortedArr2[size1 + size2 - DEFAULT] = sortedArr1[size1 - DEFAULT];
		combineArrays(sortedArr1, size1 - DEFAULT, sortedArr2, size2);// Recursive call when size2 == 0
		
		
	}

}
//****
//*			countSmaller Function
//*Recursive int function - log(n) complexity based on binary search.
//*Returns ---> The amount of numbers that lesser than num argument .
//*Assumptions--> The arr[] is sorted + all the numbers inside arr[] are foreings.
//*****
int countSmaller(int arr[], int start, int end, int num)
{
	if (start > end)
	{
		return start;
	}
	int mid = start + ((end - start) / 2);
	if (arr[mid] < num)
	{

		return countSmaller(arr, mid + DEFAULT, end, num);
		
	}
	else
	{
		return countSmaller(arr, start, mid - DEFAULT, num);
	}
}
