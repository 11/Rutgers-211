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

/*
 * adds node to hash table
 */
void addNode(node** hashlist, node* newNode, int index)
{
	//if the index we mapped to is null, store the first position and exit
	if(hashlist[index] == NULL)
	{
		hashlist[index] = newNode;
		return;
	}

	//if the root nodes data is greater than the newNode data
	//add new node to the front
	else if(hashlist[index]->data > newNode->data)
	{
		//temp points to root
		node* temp = hashlist[index];
		//add newNode to front by pointing to the old root
		newNode->next = temp;
		//add the new root to the front of the array
		hashlist[index] = newNode;
		
	}
	
	//go to the beginning of index that the bode wants to be hased too
	//will act as our itereating variable
	
	//node* bucketptr = hashlist[index];

	//while(newNode->data < bucketptr->next->data )
}

void printlist(node** hashlist, int size)
{
	printf("\n********************************************\n");

	int i;
	for(i=0; i<size; i++)
	{
		node* itr = hashlist[i];
		int bincount=0;
		while(itr!=NULL)
		{
			printf("\thashlist[%d][%d] - data: %llu \n", i, bincount, itr->data);
			itr=itr->next;
			bincount++;
		}
		printf("********************************************\n\n");	
	}
}
