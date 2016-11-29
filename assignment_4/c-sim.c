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
	int length;
	CacheBlock** set_blocks;
} CacheSet;

typedef struct{
	int length;
	CacheSet** cache_sets;
}Cache;

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
 * Creates a fully structured cache
 */
Cache* create_cache(int num_of_sets, int num_of_blocks);

/*
 * Direct Map Cache has 1 cache line per set, a cache look-up can target the set you are seeking out directly
 */
void direct_map_cache(char read_or_write);

/*
 * Mimics fully associative cache: Cache has 1 set and all cache blocks go into that one set.
 */
void full_assoc(char read_or_write);

/*
 * Mimics a N-set associative cache: Cache is split up into sets, where each set has n cache lines. 
 */ 
void n_set_assoc(char read_or_write);

int main(int args, char **argv){
	
	/* 
	Gets all the information that we need to read in the beginning of the program
	InputData* input = (InputData*) malloc(sizeof(InputData));
	input->cache_size = atoi(argv[1]);
	input->ass        = argv[2];
	input->block_size = atoi(argv[3]);
	input->rep_poly   = argv[4];
	input->write_poly = argv[5];
	*/
	
	//create the cache
	//read the file
	//take info from file and read and write info to and from the cache
	//use LRU or FIFO as data is bring written to the cache
	
	Cache* cache = create_cache(10,10);
	printf("%d\n",cache->cache_sets[0]->set_blocks[0]->tag_bits);

	exit(0);	
	
	
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
	}
	fclose(file);	
}

/*
 * Goes through and allocates memory needed for an entire cache
 */ 
Cache* create_cache(int num_of_sets, int num_of_blocks){

	Cache* new_cache = (Cache*) malloc(sizeof(Cache));
	new_cache->length = num_of_sets;

	new_cache->cache_sets = (CacheSet**) malloc(num_of_sets * sizeof(CacheSet*));
	
	int x,y;
	for(x=0; x<num_of_sets; x++)
	{
		new_cache->cache_sets[x] = (CacheSet*) malloc(sizeof(CacheSet));
		new_cache->cache_sets[x]->length=num_of_blocks;

		new_cache->cache_sets[x]->set_blocks = (CacheBlock**) malloc(num_of_blocks * sizeof(CacheBlock*));
		for(y=0; y<num_of_blocks; y++){
			new_cache->cache_sets[x]->set_blocks[y] = (CacheBlock*)malloc(sizeof(CacheBlock));
			
			new_cache->cache_sets[x]->set_blocks[y]->valid_bit = false;
			new_cache->cache_sets[x]->set_blocks[y]->dirty_bit = false;
			new_cache->cache_sets[x]->set_blocks[y]->tag_bits = 0;
			new_cache->cache_sets[x]->set_blocks[y]->index_bits = 0;
		}
	}

	return new_cache;
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





