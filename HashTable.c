#include <stdio.h>
#include <stdlib.h>



typedef struct Bucket Bucket;
typedef struct HashTable HashTable;

struct Bucket
{
	char* key;
	int value;
	Bucket* next;
};


typedef struct HashTable
{
	Bucket* data;
	int size;
} HashTable;

/*
HashTable Constructor
*/
HashTable* newHashTable(int size)
{
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));

	if (hashTable == NULL)
	{
		return NULL;
	}

	hashTable->size = size;
	hashTable->data = (Bucket*)malloc(sizeof(Bucket) * size);

	for (int i = 0; i < size; i++)
	{
		//*(hashTable->data + i) = NULL;
	}

	return hashTable;
}



/*
Bucket Constructor
*/
Bucket* newBucket(char* key, int value)
{
	Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));

	if (bucket == NULL)
	{
		return NULL;
	}

	bucket->key = key;
	bucket->value = value;
	bucket->next = NULL;

	return bucket;
}

/*
* just some hash function used to this code
* can replace with any other hash function
*/
int hashing(char* key, int tableSize)
{
	int hash = 0;

	for (int i = 0; key[i] != '\0'; i++)
	{
		hash = (hash + key[i] * i) % tableSize;
	}

	return hash;
}

int main(int argc, char** argv)
{
	return 0;
}