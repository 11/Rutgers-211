/*
 * AUTHOR: Douglas Rudolph
 * ASSIGNMENT: 1 
 * FILE: third.c
 * CREATED: 9/24/2016
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * general struct for a node
 */ 
struct Node
{
	int val;
	struct Node* next;
};

/*
 * allocates memory for a node
 * returns the newly crated node
 */
struct Node* createNode(int value)
{
	struct Node* node = (struct Node *) malloc(sizeof(struct Node));
	node->val = value;
	node->next = NULL;
	
	return node;
}

/*
 * runs through the list and removes a node
 */
struct Node* deleteNode(struct Node* root, int deleteNode)
{
	if(root == NULL)
	{
		return root;
	}

	//if the first one is the one that needs to be deleted
	if(root->val == deleteNode)
	{
		struct Node* temp = root->next;
		
		free(root);
		root = &(*temp);
		return root;
	}

	//if any node following the first needs to be deleted
	else
	{
		struct Node* itr = root;

		while(itr->next != NULL)
		{
			if(itr->next->val == deleteNode)
			{
				struct Node* temp = itr->next;
				
				//make itr point to the element after the one that is going to be deleted
				itr->next = itr->next->next;
				free(temp);
				break;
			}
		
			itr = itr->next;
		}

		return root;
	}
}

/*
 * 1. Checks to see if the node beinning added is in the linked list.
 * 	- If it is not in the linked list, add it in its proper position
 * 	- If it is in the linked list, return
 */
struct Node* addNode(struct Node* root, int newNodeData)
{	
	//if there is only one item in the list, create a node and return
	if(root==NULL)
	{	
		root = createNode(newNodeData);	
		return root;
	}
	
	
	//if the root node is greater than the newNodeData, add the new node to the front
	//"Make the newNodeData" the root node
	else if(root->val > newNodeData)
	{
		struct Node* tmp = createNode(newNodeData);
		tmp->next = root;
		root = tmp;

		return root;
	}
	
	//otherwise, add the node to the middle/end of the linked list
	else
	{
		struct Node *itr = root;

		while(itr->next != NULL)
		{	
			//if the node is already in the linked list
			if(itr->next->val == newNodeData)
			{
				return root;
			}
		
			//if we reach a node that is greater than the one being added, add it gets added in between itr and next
			else if(itr->next->val > newNodeData)
			{	
				struct Node* tmp = itr->next;

				itr->next = createNode(newNodeData);
				itr->next->next = tmp;
				return root;
			}
			itr= itr->next;
		}
	
		itr->next = createNode(newNodeData);
		return root;
	}
	
}

/*
 * takes in a starting node and prints the linked list
 */
void printList(struct Node *root)
{
	struct Node *itr = root;
	
	while(itr != NULL)
	{
		printf("%d ",itr->val);		
		itr = itr->next;
	}
	printf("\n");
}

/*
 * Check Your Fucking Syntax
 */
int CYFS(char* filename)
{
	//open the file stream
	FILE* file = fopen(filename, "r");
	
	if(file == NULL)
	{
		printf("error");
		return -1;
	}
	
	const int MAX_BUFFER = 20; 
	char str[MAX_BUFFER];
	
	//loop through and check syntax
	while((fgets(str, MAX_BUFFER, file))!=NULL)
	{		
		if(((str[0] == 'i' || str[0] == 'd')
			&& str[1] == '\t' 
			&& ((str[2] > 47 && str[2] < 58) || (str[2] == '-' && str[3] > 47 && str[3] < 58))) 
			
			|| str[0]=='\0')
		{
			//loop through while there are numbers
			int i;
			
			//loop through all the numbers
			for(i=(str[2]=='-')?3:2; str[i] > 47 && str[i]< 58 && i<MAX_BUFFER; i++){}

			//check to make sure nothing follows the number in the file besides a new line
			if(str[i] == '\n' || str[i]=='\0')
				continue;
			else 
			{
				fclose(file);
				return -1;
			}
		}
		else
		{
			fclose(file);
			return -1;
		}
	}
	
	fclose(file);
	return 1;
}

/*
 * Takes the information, parses the file, sends the the values from the linked list to be built
 */
struct Node* parseFile(struct Node* root, char* filename)
{
	FILE* file = fopen(filename, "r");
	const int MAX_BUFFER = 20;
	char str[MAX_BUFFER];
	
	while((fgets(str, MAX_BUFFER, file))!=NULL)
	{	
		int i, pos=0;
		char num[MAX_BUFFER];
		
		//add the negative to a char string
		if(str[2]=='-')
		{
			num[0]='-';
			pos=1;
		}
		
		//loop through to get the numbers 
		for(i=(str[2]=='-')?3:2;str[i] > 47 && str[i]< 58 && i<MAX_BUFFER; i++, pos++)
		{
			num[pos]=str[i];		
		}
		
		//cast char number buffer from file to and int
		int x = atoi(num);	
		char op = str[0];
		
		if(op == 'i')
		{
			root = addNode(&(*root), x);
			
		}
		else if(op == 'd')
		{
			root = deleteNode(&(*root), x);
		}
	}

	fclose(file);
	return root;
}

/*
 * main function
 */
int main(int argc, char **argv)
{	
	struct Node* root = NULL;
	
	int canRun = CYFS(argv[1]);

	if(canRun == 1)
	{	
		root = parseFile(&(*root), argv[1]);
	}
	printList(root);
		
	return 0;
}
