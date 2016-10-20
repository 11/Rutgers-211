#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

typedef struct hash_node{
	unsigned long long data;
	struct hash_node* next;
}node;

//HashTable struct that acts as a object
typedef struct hash{
	int size;
	node** hashlist;
	void (*rehash)(node);
	int (*hash)(node, int);
	void (*addNode)(node**, node*, int);
	void (*printlist)(node**, int);
}HashTable;

void rehash(node value);

int hash(node value, int size);

void addNode(node** hashlist, node* newNode, int index);

void printlist(node** hashlist, int size);

//generic hashtable struct
#define DEFAULT_HASH {1, calloc(1, sizeof(node)), &rehash, &hash, &addNode, &printlist};

