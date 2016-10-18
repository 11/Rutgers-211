#include <stdio.h>
#include <string.h>
#include "bool.h"

/**
 * param - filename: filename asstring
 * param - hashlist-ptr: ptr to double ptr hashtable
 * param -  
 */
void readfile(char* filename)
{
	FILE* file = fopen(filename,"r");
	
	if(file == NULL)
	{
		printf("error\n");
		return;
	}

	unsigned long long hex_val=0;

	while(fscanf(file, "%llx",&hex_val)!=EOF)
	{	
		//position in the hashtable
		//int pos = 
		//(*hashlist_ptr)[] = hex_val
	}

} 
