#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void deleteHashTable(HashTable* hashTable)
{
	Bucket* curr = NULL;
	Bucket* next = NULL;

	for (int i = 0; i < hashTable->size; i++)
	{
		if (hashTable->data[i] != NULL)
		{
			curr = hashTable->data[i];
			next = curr->next;

			while (next != NULL)
			{
				free(curr);
				curr = next;
				next = next->next;
			}
		}
		curr = NULL;
	}

	free(hashTable->data);
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

/*
this function adds an organ to the map
*/
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

		do
		{
			if (strcmp(curr->key, key) == 0)
			{
				curr->value = value;
				return;
			}

			curr = curr->next;
		} while (curr->next != NULL);

		curr->next = newBucket(key, value);
	}
}

/*
this function gets the value of an organ by its key
*/
int get(char* key, HashTable* hashTable)
{
	int index = hashing(key, hashTable->size);
	Bucket* curr = hashTable->data[index];

	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
		{
			return curr->value;
		}

		curr = curr->next;
	}
	
	return -1;
}

int main(int argc, char** argv)
{
	HashTable* hashTable = newHashTable(5);
	set("hello", 3, hashTable);
	set("XD", 212, hashTable);
	set("kend", 12, hashTable);
	printf("%d\n", get("hello", hashTable));
	printf("%d\n", get("XD", hashTable));
	printf("%d\n", get("kend", hashTable));
	set("kend", 32, hashTable);
	printf("%d\n", get("kend", hashTable));
	deleteHashTable(hashTable);

	
	return 0;
}
