#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct{
	int cache_size;
	char* ass;
	int set_size;
	int block_size;
	char* rep_poly;
	char* write_poly;
	FILE* file;
} InputData;

typedef struct{
	bool valid_bit;
	bool dirty_bit;
	short tag_bits;
	short index_bits;
} CacheBlock;

typedef struct{
	int size;
	CacheBlock [size];
} CacheSet;

typedef struct{
	int mem_reads;
	int mem_writes;
	int cache_hits;
	int cache_misses;
} ProjectStats;

/*
 * Runs the cache simulator
 */ 
void run(char* filename);

/*
 * Direct Map Cache has 1 cache line per set, a cache look-up can target the set you are seeking out directly
 */
void direct_map_cache(char read_or_write);

/*
 * Miims fully associative cache: Cache has 1 set and all cache blocks go into that one set.
 */
void full_assoc(char read_or_write);

/*
 * Mimics a N-set associative cache: Cache is split up into sets, where each set has n cache lines. 
 */ 
void n_set_assoc(char read_or_write);


int main(int args, char **argv){
	
	/*
	 * Gets all the information that we need to read in the beginning of the program
	InputData* input = (InputData*) malloc(sizeof(InputData));
	input->cache_size = atoi(argv[1]);
	input->ass        = argv[2];
	input->block_size = atoi(argv[3]);
	input->rep_poly   = argv[4];
	input->write_poly = argv[5];
	*/
	
	run("mytrace.txt");


	return 0;
}

void run(char* filename){
	//file that we are running the cache simulator on
	FILE* file=fopen(filename, "r");
	
	//stores if I am reading or writing to the cache
	char read_or_write;

	//memory address of where information is written to
	long mem_add;	

	//reads the data from a file until EOF
	while(fscanf(file, "%*x %*2s %c %x", &read_or_write, &mem_add)){
		
		if(read_or_write == 'W'){
			//do the thing

		}
		else if(read_or_write == 'R'){
			//do the other thing
			
		}
		
		printf("%c\n", read_or_write);
		printf("%x\n", mem_add);
	}
	fclose(file);	
}

/*
 * simulates a cache using direct map caching
 */
void direct_map_cache(char read_or_write){

	//if read 
	if(read_or_write == 'R'){
				
	}

	//if write
	if(read_or_write =='W'){
	
	}

}





