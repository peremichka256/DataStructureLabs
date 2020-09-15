#pragma once
#include "CommonFunc.h"
#include "HashTable.h"
#include "Dictionary.h"

void PrintMainMenuText();
void PrintMenuHashTableText();
void PrintMenuDictionaryText();
int StartMenuHashTable(HashTable* hashTable);
int StartMenuDictionary(Dictionary* dictionary);
void ShowTable(HashTable* hashTable);
void ShowDictonary(Dictionary* dictonary);
void PrintErrorInsert();
void PrintErrorRemove();
void PrintErrorRepeat();
void PrintNode(Node* node, int index);
string InputKeyOrValue();