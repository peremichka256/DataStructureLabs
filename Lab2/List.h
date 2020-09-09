#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

struct List
{
	int Size;
	Node* Head;
	Node* Tail;
};

void MenuText();
List* CreatingList();
void Initialization(List*, int itemNumber);
void AddItem(List*, int index, int newItemValue);
void Sort(List*);
int LineSearch(List*, int searchItem);
void ShowList(List*);
void DeleteList(List*);
void DeleteItem(List*, int index);
bool IsListEmpty(List*);
bool CheckingForInteger(string value);
int InputValidation(int min, int max);
Node* GetNode(List*, int index);

const int MIN_NUMBER_ITEMS = 0;
const int MAX_NUMBER_ITEMS = 100;
const int MIN_VALUE_ITEMS = -100;
const int MAX_VALUE_ITEMS = 100;
const int MAX_INTEGER = 11;