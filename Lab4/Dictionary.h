#pragma once
#include "HashTable.h"

struct Dictionary
{
	HashTable* Table;
};

Dictionary* CreateDictionary();
//TODO: naming
Node* FindValue(Dictionary*, string);
bool InsertByKey(Dictionary*, Node*, string);
bool RemoveByKey(Dictionary*, string);
void DeleteDictionary(Dictionary* dictionary);

int const MIN_DICTIONARY_SIZE = 4;