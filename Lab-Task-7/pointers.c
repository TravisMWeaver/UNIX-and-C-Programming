#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define ARRAY_LENGTH 5

typedef int *IntPtr;
typedef int IntArray[ARRAY_LENGTH];
typedef int *IntPtrArray[ARRAY_LENGTH];

pid_t getpid(void);

void initialize(IntArray RandArray, IntPtrArray PtrArray)
{
	int i;
	srand(getpid());

	for(i = 0; i < ARRAY_LENGTH; i++)
	{
		RandArray[i] = rand();
		PtrArray[i] = &(RandArray[i]);
	}
}

void print(IntArray RandArray)
{
	int i;

	for(i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("%d : %d\n", i, RandArray[i]);
	}
}

void printPtr(IntPtrArray PtrArray)
{
	int i;

	for(i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("%d : %d\n", i, *PtrArray[i]);
	}
}

void bubbleSort(IntArray RandArray)
{
	int i, j;
	int temp;

	for(i = 0; i < ARRAY_LENGTH - 1; i++)
	{
		for(j = 0; j < ARRAY_LENGTH - 1; j++)
		{
			if(*(RandArray + j) > *(RandArray + j + 1))
			{
				temp = *(RandArray + j);
				*(RandArray + j) = *(RandArray + j + 1);
				*(RandArray + j + 1) = temp;
			}
		}
	}
}

void bubbleSortPtr(IntPtrArray PtrArray)
{
	int i, j;
	IntPtr temp;

	for(i = 0; i < ARRAY_LENGTH - 1; i++)
	{
		for(j = 0; j < ARRAY_LENGTH - 1; j++)
		{
			if(*(PtrArray[j]) > *(PtrArray[j + 1]))
			{
				temp = PtrArray[j];
				PtrArray[j] = PtrArray[j + 1];
				PtrArray[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	IntArray RandArray;
	IntPtrArray PtrArray;

	initialize(RandArray, PtrArray);

	printf("---- Initialized array of integers ----\n");
	print(RandArray);

	bubbleSortPtr(PtrArray);

	printf("---- Sorted array of pointers ----\n");
	printPtr(PtrArray);

	bubbleSort(RandArray);

	printf("---- Sorted array of integers ---\n");
	print(RandArray);

	printf("---- Array of pointers ----\n");
	printPtr(PtrArray);

	return(EXIT_SUCCESS);
}