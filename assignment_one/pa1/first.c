#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		printf("error\n");
		return 0;
	}
	
	int val = atoi(argv[1]);

	if(val % 2 == 0)
		printf("even\n");
	else
		printf("odd\n");

	return 0;
}
