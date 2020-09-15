#pragma once
#include "HashTable.h"

struct Dictionary
{
	HashTable* Table;
};

Dictionary* CreateDictionary();
Node* FindValue(Dictionary* dictionary, string key);
bool InsertByKey(Dictionary* dictionary, Node* insertedNode, string key);
bool RemoveByKey(Dictionary* dictionary, string key);
void DeleteDictionary(Dictionary* dictionary);

int const MIN_DICTIONARY_SIZE = 4;