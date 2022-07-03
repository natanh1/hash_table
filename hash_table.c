#include <stdio.h>
#include <stdlib.h>

struct HashTable
{
	int* data;
	int size;
} typedef HashTable;

HashTable* newHashTable(int size)
{
	HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
	hashTable->size = size;
	hashTable->data = (int*)malloc(sizeof(int) * size);

	return hashTable;
}

int main(int argc, char** argv)
{
	return 0;
}