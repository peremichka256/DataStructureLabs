#pragma once
#include "Chain.h"

struct HashTable
{
	int	NumberOfFilledNodes;
	int Size;
	Chain** Array;
};

HashTable* CreateTable(int size);
Node* CreateNewNode(string key, string value);
bool InsertNode(HashTable* hashTable, Node* insrtedNode, int);
bool RemoveNode(HashTable* hashTable, string key);
Node* FindNode(HashTable* hashTable, string key);
int HashFunction(string key, int twoPrimeNumber);
void CollisionResolution(Node* chainBegin, Node* insertedNode);
HashTable* Rehashing(HashTable* oldTable);
void DeleteTable(HashTable* hashTable);

int const MIN_HASHTABLE_SIZE = 4;
double const GROWTH_FACTOR = 1.6;