#include <stdio.h>
#include <stdlib.h>

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

	

}Cache;

typedef struct{
	int mem_reads;
	int mem_writes;
	int cache_hits;
	int cache_misses;
}ProjectStats;


void fifo();

void lru();

int main(int args, char **argv){
	
	InputData* input = (InputData*) malloc(sizeof(InputData));
	
	input->cache_size = atoi(argv[1]);
	input->ass        = argv[2];
	input->block_size = atoi(argv[3]);
	input->rep_poly   = argv[4];
	input->write_poly = argv[5];

	//printf("%d %s %d %s %s", input->cache_size, input->ass, input->block_size, input->rep_poly, input->write_poly);
	return 0;
}




