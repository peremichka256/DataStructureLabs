#pragma once
#include "CommonFunc.h"
#include "HashTable.h"
#include "Dictionary.h"

void MainMenuText();
void MenuHashTableText();
void MenuDictionaryText();
int MenuHashTable(HashTable*);
int MenuDictionary(Dictionary*);
void ShowTable(HashTable* hashTable);
void ShowDictonary(Dictionary* dictonary);
void ErrorMessegeInsert();
void ErrorMessegeRemove();
void ErrorMessegeRepeat();
void PrintNode(Node*, int);
string InputKeyOrValue();