#ifndef HashNode_h
#define HasnNode_h

typedef struct hash_node{
	unsigned long long data;
	struct hash_node* next;
}node;

node* create_node(unsigned long long data);

#endif
