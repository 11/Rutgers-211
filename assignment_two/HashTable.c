#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * acts as the hash function to a hashtable
 */ 
int get_hash_index(unsigned long long value, int size)
{
	int hash_val = value % size;

	return hash_val;
}

/*
 * adds node to hash table
 */
bool hash(node** hashlist, node* newNode, int index)
{
	//if the index we mapped to is null, store the first position and exit
	if(hashlist[index] == NULL)
	{
		hashlist[index] = newNode;
		return true;
	}

	else if(hashlist[index]->data == newNode->data)
	{
		return false;
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

	//otherwise, add the node to the middle/end of the linked list
	else
	{	
		node *itr = hashlist[index];

		while(itr->next != NULL)
		{	
			//if the node is already in the linked list
			if(itr->next->data == newNode->data)
			{
				return false;
			}
				
			//if we reach a node that is greater than the one being added, add it in between itr and next
			else if(itr->next->data > newNode->data)
			{	
				node* tmp = itr->next;
				itr->next = newNode;
				itr->next->next = tmp;
				return true;
			}
			itr= itr->next;
		}
	
		itr->next = newNode;
		return true;
	}
	return false;
}

node **rehash(node** hashlist, int size)
{	
	printf("size: %d\n", size);	
	
	node** newlist = (node**) malloc(sizeof(node*)*size*2);

	int i;
	for(i = 0; i<size; i++)
	{
		if(hashlist[i] == NULL)
		{
			continue;
		}
		else
		{	
			node* itr = hashlist[i];
			while(itr != NULL)
			{
				hash(newlist, itr, get_hash_index(itr->data, size*2));
				itr = itr->next;
			}
		}
	}
	return newlist;
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
