#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "cstring"
int main(int argc, char* argv[])
{
	int tmp;
	int number = argc;
	int* arr = (int*)calloc(number, sizeof(int));
	for (int i = 0; i < number; i++)
	{
		arr[i] = atoi(argv[i + 1]);
	}
	for (int i = 0; i < number; i++)
	{
		for (int j = i+1; j < number; j++)
		{
			if (arr[i]>arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	FILE *f;
	f = fopen(strcat(argv[number], "out.txt"), "wt");
	for (int i = 0; i < number; i++)
	{
		fprintf(f, "%d\n", arr[i]);
	}
	fclose(f);
	return 0;
}

