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
}HashTable;

void rehash(node value);

int hash(node value, int size);

//generic hashtable struct
#define DEFAULT_HASH {0, calloc(1, sizeof(node)), &rehash, &hash};

