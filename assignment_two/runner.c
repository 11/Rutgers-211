#include "HashTable.h"
#include "filereader.h"
#include <stdlib.h>


int main(int argc, char** argv)
{	
	node* test1 = (node*) malloc(sizeof(node));
	test1->data = 1;

	node* test2 = (node*) malloc(sizeof(node));
	test2->data = 5;

	node* test3 = (node*) malloc(sizeof(node));
	test3->data = 3;

	node* test4 = (node*) malloc(sizeof(node));
	test4->data = 0;

	HashTable table = DEFAULT_HASH;
		
	table.addNode(table.hashlist, test1, 0);
	table.addNode(table.hashlist, test2, 0);
	table.addNode(table.hashlist, test3, 0);
	table.addNode(table.hashlist, test4, 0);


	table.printlist(table.hashlist, table.size);	

	return 0;
}

