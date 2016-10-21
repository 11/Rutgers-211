#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{	
	HashTable table = DEFAULT_HASH;
	
	//init everything to nulll
	int i;
	for(i=0; i<table.size; i++)
	{
		table.hashlist[i] = NULL;
	}
	
	FILE* file = fopen(argv[1],"r");
	
	if(file == NULL)
	{
		printf("error\n");
		return 0;
	}

	int count_diff = 0;

	unsigned long long hex_val=0;
	while(fscanf(file, "%llx",&hex_val)!=EOF)
	{	
		//for debug purposes
		//printf("hex_val %llx\n", hex_val);
		
		//get the index where the node should be stored
		int index = table.get_hash_index(hex_val, table.size);
		
		//create node
		node* newNode = create_node(hex_val);
		newNode->data = hex_val;
		
		printf("************************\n");
		printf("hex_val: %llu\n", hex_val);
		printf("index: %d\n", index);
		printf("size: %d\n", table.size);
		printf("*************************\n\n");
	
		//hash
		//if 
		if(count_diff < table.size)
		{
			bool isNewVal = table.hash(table.hashlist, newNode, index);
			
			//if the hash function stored a new value in the array
			if(isNewVal == true)
			{
				count_diff++;	
			}
		}

		//rehash
		else
		{
			table.hashlist = rehash(table.hashlist, table.size);
			table.size *= 2;
		}

	}

	//debug purposes
	//table.printlist(table.hashlist, table.size);	

	printf("%d\n", count_diff);
	return 0;
} 

