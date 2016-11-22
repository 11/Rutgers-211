/*
 * AUTHOR: Douglas Rudolph
 * FILE: fourth.c
 * CREATED: October 3rd, 2016
 * CLASS: Computer Architecure - 211
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

struct HashNode
{
	bool isFilled;
	int data;
};

/*
 * returns the absolute value 
 */
int lazyHash(int key)
{
	return abs(key)%1000;
}

/*
 * checks to see if the line is compatiable has no errors
 */
bool lineCheck(char str[])
{
	const int MAX_BUFFER = 20;

	if( (str[0]=='i' || str[0] == 's') 
		&& str[1]=='\t' 
		&& ((str[2] == '-' && str[3] > 47 && str[3]< 58 ) || (str[2] > 47 && str[2] < 58)))
	{
			
		int i;
		for(i=(str[2]=='-')?3:2; str[i]>47 && str[i]<58 && i < MAX_BUFFER; i++){}
		
		if(str[i] == '\n' || str[i] == '\0')
		{
			return true;
		}

	}
	return false;
}

/*
 * extract the number fromt the line
 */
int extractNumber(char str[])
{
	const int MAX_BUFFER = 20;
	int i, pos=0;

	char num[MAX_BUFFER];

	for(i = 2; str[i]>47 && str[i]<58 && i< MAX_BUFFER; i++, pos++)
	{
		num[pos] = str[i];
	}

	int inLineValue = atoi(num);

	return inLineValue;
}

/*
 * Determines if there is a position for the hashed value to be stored
 * 	- If there is a no position open or if inLineValue is already inside: returns -1
 * 	- If there is a position for the value: returns <storing_pos>
 */
int choosePosition(int inLineValue, struct HashNode lazyHashTable[])
{
	//keeps track of how many nodes are in the hash table overall
	static int HASH_COUNT = 0;
	
	//the initial position that hash function returns
	int naturalPos = lazyHash(inLineValue);	
	
	//if the initial position is not filled
	if(lazyHashTable[naturalPos].isFilled==false)
	{
		//return the natural position from the hash function returns 
		//(no linear probing needed)
		return naturalPos;
	}

	//if the initial position is filled and the hashtable isnt filled, loop through to find the next open position
	else if(HASH_COUNT < 1000)
	{
		int itr=naturalPos;

		while(lazyHashTable[itr].isFilled == false)
		{
			//if it can't find a position from x to 1000, wrap to 0
			if(itr==1000)
			{
				itr=0;
				continue;
			}	
			
			//if the inLineValue is in the list, just return
			if(lazyHashTable[itr].data == inLineValue)
			{
				return -1 ;
			}
			
			itr++;				
		}
		//increment that Hash table size counter
		HASH_COUNT++;
		
		//retun the linearly probbed position
		return itr;
	}
	
	//returns -1 if there are no open positions;
	return -1;
}


/*
 *
 */
int main(int argc, char **argv)
{	
	char* filename = argv[1];
	
	//create a struct 
	struct HashNode lazyHashTable[1000];	
	
	//populate Hash Table
	int i;
	for(i=0; i < 1000; i++)
	{
		lazyHashTable[i].isFilled = false;
		lazyHashTable[i].data = -1;
	} 
			
	FILE* file = fopen(filename, "r");
	
	if(file == NULL)
	{
		printf("error\n");
		return 0;
	}
	
	const int MAX_BUFFER = 20;
	
	char str[MAX_BUFFER];	
	
	//loop through the file
	while((fgets(str,MAX_BUFFER,file))!=NULL)
	{
		//if the fiie has the correct format
		bool properFormat = lineCheck(str);

		//if line has proper syntax
		if(properFormat == true)
		{
			//extract the number from the line that fgets gives us
			int inLineValue = extractNumber(str);

			//printf("extractNumber: %d", inLineValue);

			if(str[0] =='i')
			{
				//if there is a position in the array, store the position in the next open element
				if(choosePosition(inLineValue, lazyHashTable) != -1)
				{
					lazyHashTable[choosePosition(inLineValue, lazyHashTable)].data = inLineValue;
					printf("inserted\n");
				}
			}	

			//if the file wants you to search
			else if(str[0] == 's')
			{
				//printf("LINE: 166");
				//itr iterates through the hash table
				//check is a boolean that checks to stores if the value is in the array; assumes the inLineValue is inside
				int itr;
				bool check = false;
				for(itr = 0; itr < sizeof(lazyHashTable)/sizeof(int); itr++)
				{
					if(lazyHashTable[itr].data == inLineValue)
					{	
						printf("present\n");
						check = true;
						break;
					}
				}
			
				if(check == false)
				{
					printf("absent\n");
				}
			}
		}
		else
		{
			printf("error\n");
		}
	}
	//close the file stream
	fclose(file);
	
	return 0; 
}
