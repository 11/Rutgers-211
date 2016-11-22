#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int val = atoi(argv[1]);

	if(val % 2 == 0)
		printf("even\n");
	else
		printf("odd\n");

	return 0;
}
