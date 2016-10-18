#include "HashTable.h"


/**
 * acts as the hash function to a hashtable
 */ 
int hash(node value, int size)
{
	return value.data % size;
}

/**
 * acts as the rehash function to a hashtable
 */
void rehash(node value)
{
	
}
