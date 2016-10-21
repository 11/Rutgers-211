#ifndef HashTable_h
#define HashTable_h

#include "HashNode.h"

//HashTable struct that acts as a object
typedef struct hash{
	int size;
	node** hashlist;
	void (*rehash)(node);
	int (*get_hash_index)(unsigned long long, int);
	void (*addnode)(node**, node*, int);
	void (*printlist)(node**, int);
}HashTable;

void rehash(node value);

int get_hash_index(unsigned long long value, int size);

void addnode(node** hashlist, node* newNode, int index);

void printlist(node** hashlist, int size);

//generic hashtable struct
#define DEFAULT_HASH {1, calloc(1, sizeof(node)), &rehash, &get_hash_index, &addnode, &printlist};

#endif
