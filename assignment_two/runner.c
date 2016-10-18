#include "HashTable.h"
#include "filereader.h"
#include <stdlib.h>


int main(int argc, char** argv)
{	
	node* test = (node*) malloc(sizeof(node));
	test->data = 98989998898998;
	
	HashTable table = DEFAULT_HASH;
	table.hashlist[0] = test;
	printf("%d\n",table.size);
	printf("%llx\n", table.hashlist[0]->data);

	return 0;
}

