/*
 * AUTHOR: Douglas Rudolph
 * CREATED: October 4th, 2016
 * FILE: fifth.c
 * CLASS: Computer Architecture
 */
#include <stdio.h>
#include <stdlib.h>


/*
 *
 */
int main(int argc, char **argv)
{
	
	//create boolean type
	//typedef enum{true, false} bool;
	
	//opens file
	FILE* file = fopen(argv[1], "r");

	int x=0;
	int y=0;
	fscanf(file, "%d", &x);
	fscanf(file, "%d", &y);

	int matrix[x][y];

	int i,j;

	for(i=0; i < x; i++)
	{
		for(j=0; j < y; j++)
		{
			fscanf(file, "%d", &matrix[i][j]);
		}
	}

	for(i=0; i < x; i++)
	{
		for(j=0; j < y; j++)
		{	
			int val = 0;
			fscanf(file, "%d", &val);
			printf("%d\t", matrix[i][j]+val);
		}
		printf("\n");
	}

	fclose(file);
	return 0;
}
