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
	Bucket** data;
	int size;
} HashTable;

/*
HashTable Constructor
*/
HashTable* newHashTable(int size)
{
	if (size <= 0)
	{
		return NULL;
	}

	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));

	if (hashTable == NULL)
	{
		return NULL;
	}

	hashTable->size = size;
	hashTable->data = (Bucket**)malloc(sizeof(Bucket*) * size);

	for (int i = 0; i < size; i++)
	{
		hashTable->data[i] = NULL;
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
	int index = 0;

	for (int i = 0; key[i] != '\0'; i++)
	{
		index = (index + key[i] * i) % tableSize;
	}

	return index;
}

void set(char* key, int value, HashTable* hashTable)
{
	int index = hashing(key, hashTable->size);
	Bucket* curr = NULL;

	if (hashTable->data[index] == NULL)
	{
		hashTable->data[index] = newBucket(key, value);
	}
	else
	{
		curr = hashTable->data[index];

		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		curr->next = newBucket(key, value);
	}
}

int get(char* key)
{
	return 0;
}

int main(int argc, char** argv)
{
	HashTable* hashTable = newHashTable(5);
	set("hello", 3, hashTable);


	
	return 0;
}