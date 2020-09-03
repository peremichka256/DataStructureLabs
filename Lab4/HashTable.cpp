#include "HashTable.h"

HashTable* CreateTable(int size)
{
	HashTable* hashTable = new HashTable;
	hashTable->Size = size;
	hashTable->NumberOfFilledNodes = 0;
	hashTable->Array = new Chain*[hashTable->Size];

	for (int i = 0; i < hashTable->Size; i++)
	{
		Chain* newChain = new Chain;
		hashTable->Array[i] = newChain;
		hashTable->Array[i]->ChainSize = 0;
		hashTable->Array[i]->Head = nullptr;
	}
	return hashTable;
}

Node* CreateNewNode(string key, string value)
{
	Node* newNode = new Node;
	newNode->Key = key;
	newNode->Value = value;
	newNode->Next = nullptr;
	return newNode;
}

bool InsertNode(HashTable* hashTable, Node* insertedNode, int newNodeChainIndex)
{
	Node* current = hashTable->Array[newNodeChainIndex]->Head;

	while (current != nullptr)
	{
		if ((current->Key == insertedNode->Key)
			&& (current->Value == insertedNode->Value))
		{
			return false;
		}
		current = current->Next;
	}

	if (hashTable->Array[newNodeChainIndex]->Head == nullptr)
	{
		hashTable->Array[newNodeChainIndex]->Head = insertedNode;
	}
	else
	{
		CollisionResolution(hashTable->Array[newNodeChainIndex]->Head,
			insertedNode);
	}
	hashTable->Array[newNodeChainIndex]->ChainSize++;
	hashTable->NumberOfFilledNodes++;
	return true;
}

bool RemoveNode(HashTable* hashTable, string key)
{
	int removeNodeChainIndex = HashFunction(key, hashTable->Size);
	bool isNeedRemove = false;

	if (hashTable->Array[removeNodeChainIndex]->ChainSize != 0)
	{
		Node* current = hashTable->Array[removeNodeChainIndex]->Head;
		int counter = 0;

		while (current != nullptr)
		{
			if (current->Key == key)
			{
				counter++;
				isNeedRemove = true;
			}
			current = current->Next;
		}

		if (isNeedRemove == false)
		{
			return false;
		}

		while (counter != 0)
		{
			if (hashTable->Array[removeNodeChainIndex]->Head->Key == key)
			{
				Node* removeNode = hashTable->Array[removeNodeChainIndex]->Head;
				hashTable->Array[removeNodeChainIndex]->Head
					= hashTable->Array[removeNodeChainIndex]->Head->Next;
				delete removeNode;
			}
			else
			{
				Node* prevRemoveNode 
					= hashTable->Array[removeNodeChainIndex]->Head;
				int secondCounter = 0;

				while (prevRemoveNode->Next->Key != key)
				{
					secondCounter++;
					prevRemoveNode = prevRemoveNode->Next;
				}
				Node* deleteNode = prevRemoveNode->Next;

				if (secondCounter 
					== hashTable->Array[removeNodeChainIndex]->ChainSize - 2)
				{
					prevRemoveNode->Next = nullptr;
				}
				else
				{
					prevRemoveNode->Next = prevRemoveNode->Next->Next;
				}
				delete deleteNode;
			}
			hashTable->NumberOfFilledNodes--;
			hashTable->Array[removeNodeChainIndex]->ChainSize--;
			counter--;
		}
		return true;
	}
	else
	{
		return false;
	}
}
	

Node* FindNode(HashTable* hashTable, string key)
{
	int desiredNodeIndex = HashFunction(key,hashTable->Size);
	Node* current;

	if (hashTable->Array[desiredNodeIndex]->Head)
	{
		current = hashTable->Array[desiredNodeIndex]->Head;
	}
	else 
	{
		return nullptr;
	}

	while (current->Key != key)
	{
		current = current->Next;

		if (current == nullptr)
		{
			return nullptr;
		}
	}
	return current;
}

int HashFunction(string key, int twoPrimeNumber)
{
	int size = key.length();
	int hash = 0;

	for (int i = 0; i < size; i++)
	{
		hash = (hash * (twoPrimeNumber - 1) + key[i]) % twoPrimeNumber;
	}
	return abs(hash);
}

void CollisionResolution(Node* chainBegin, Node* insertedNode)
{
	Node* current = chainBegin;

	while (current->Next != nullptr)
	{
		current = current->Next;
	}
	current->Next = insertedNode;
}

HashTable* Rehashing(HashTable* oldTable)
{
	int newTableSize = oldTable->Size;

	if (oldTable->Size == 1)
	{
		newTableSize++;
	}
	else
	{
		newTableSize *= GROWTH_FACTOR;
	}

	HashTable* newTable = CreateTable(newTableSize);
	
	for (int i = 0; i < oldTable->Size; i++)
	{
		Node* current = oldTable->Array[i]->Head;

		while (current != nullptr)
		{
			int index = HashFunction(current->Key, newTable->Size);
			InsertNode(newTable, current, index);
			oldTable->Array[i]->Head = current->Next;
			current->Next = nullptr;
			current = oldTable->Array[i]->Head;
		}
	}

	for (int i = 0; i < oldTable->Size; i++)
	{
		delete oldTable->Array[i];
	}
	delete[] oldTable->Array;
	delete oldTable;
	return newTable;
}

void DeleteTable(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->Size; i++)
	{
		for (int j = 0; j < hashTable->Array[i]->ChainSize; j++)
		{
			Node* removeNode = hashTable->Array[i]->Head;

			if (hashTable->Array[i]->Head->Next != nullptr)
			{
				hashTable->Array[i]->Head 
					= hashTable->Array[i]->Head->Next;
			}
			delete removeNode;
		}
		delete hashTable->Array[i];
	}
	delete[] hashTable->Array;
	delete hashTable;
}