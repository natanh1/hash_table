# Hash Table Implementation

A quick hash table implementation I made in c to understand it better

## Installation

Just download the file as raw or copy it into your project

```bash
https://github.com/natanh1/hash_table/blob/main/HashTable.c
```

## Usage

```c

# creates a new hash table
HashTable* hashTable = newHashTable(size);

# deletes the hash table
deleteHashTable(hashTable);

# sets new organ in the table - key must be a string and value must be an int
set("key", 100, hashTable);

# returns the value
get("hello", hashTable)
```
