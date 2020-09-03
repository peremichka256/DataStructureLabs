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
bool InsertNode(HashTable*, Node* insrtedNode, int);
bool RemoveNode(HashTable*, string key);
Node* FindNode(HashTable*, string key);
int HashFunction(string, int);
void CollisionResolution(Node* chainBegin, Node* insertedNode);
HashTable* Rehashing(HashTable*);
void DeleteTable(HashTable*);

int const MIN_HASHTABLE_SIZE = 4;
double const GROWTH_FACTOR = 1.6;