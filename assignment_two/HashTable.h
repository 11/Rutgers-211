#ifndef HashTable_h
#define HashTable_h
#include "bool.h"
#include "HashNode.h"

//HashTable struct that acts as a object
typedef struct hash{
	int size;
	node** hashlist;
	void (*rehash)(node**, int);
	int (*get_hash_index)(unsigned long long, int);
	bool (*hash)(node**, node*, int);
	void (*printlist)(node**, int);
}HashTable;

void rehash(node** hashlist, int size);

int get_hash_index(unsigned long long value, int size);

bool hash(node** hashlist, node* newNode, int index);

void printlist(node** hashlist, int size);

//generic hashtable struct
#define DEFAULT_HASH {5, calloc(1, sizeof(node)), &rehash, &get_hash_index, &hash, &printlist};

#endif
