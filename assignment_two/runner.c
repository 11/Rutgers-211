#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{	
	HashTable table = DEFAULT_HASH;
	
	FILE* file = fopen(argv[1],"r");
	
	if(file == NULL)
	{
		printf("error\n");
		return 0;
	}

	unsigned long long hex_val=0;

	while(fscanf(file, "%llx",&hex_val)!=EOF)
	{	
		printf("hex_val %llx", hex_val);
		
		//get the index where the node should be stored
		int index = table.get_hash_index(hex_val, table.size);
		
		//create node
		node* newNode = create_node(hex_val);
		newNode->data = hex_val;

		table.addnode(table.hashlist, newNode, index);
	}


	table.printlist(table.hashlist, table.size);	

	return 0;
} 

