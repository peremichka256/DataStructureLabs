#include "Dictionary.h"

Dictionary* CreateDictionary()
{
	Dictionary* dictionary = new Dictionary;
	dictionary->Table = CreateTable(MIN_DICTIONARY_SIZE);
	return dictionary;
}

Node* FindValue(Dictionary* dictionary, string key)
{
	return FindNode(dictionary->Table, key);
}

bool InsertByKey(Dictionary* dictionary, Node* insertedNode, string key)
{
	int newNodeChainIndex = HashFunction(key, dictionary->Table->Size);
	Node* current = dictionary->Table->Array[newNodeChainIndex]->Head;

	while (current != nullptr)
	{
		if (current->Key == insertedNode->Key)
		{
			return false;
		}
		current = current->Next;
	}
	InsertNode(dictionary->Table, insertedNode, newNodeChainIndex);
	return true;
}

bool RemoveByKey(Dictionary* dictionary, string key)
{
	return RemoveNode(dictionary->Table, key);
}

void DeleteDictionary(Dictionary* dictionary)
{
	DeleteTable(dictionary->Table);
	delete dictionary;
}