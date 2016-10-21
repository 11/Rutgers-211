#include "HashNode.h"
#include <stdlib.h>

node* create_node(unsigned long long data)
{
	node* newNode = (node*) malloc(sizeof(node));

	newNode -> data = data;
	newNode -> next = NULL;

	return newNode;
}
