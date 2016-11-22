#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{	

	if(sizeof(argv[1])==0)
	{
		printf("error\n");
		return 0;
	}

	float val = (double)atoi(argv[1]);

	float itr;
	for(itr = 2; itr < val; itr++)
	{
		float answer = (val/itr); 
		
		//converting answer to int and then back to float allows for me to remove all values after the decimal
		//hacky fix
		int temp = (int)answer;
		float whole_answer = (float)temp;

		if(answer - whole_answer == 0)
		{		
			printf("no\n");
			return 0;
		}
	} 

	printf("yes\n");
	return 0;
}
