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

void PrintMenuText();
List* CreatingList();
void Initialization(List* list, int itemNumber);
void AddItem(List* list, int index, int newItemValue);
void Sort(List* list);
int LineSearch(List* list, int searchItemValue);
void ShowList(List* list);
void DeleteList(List* list);
void DeleteItem(List* list, int index);
bool IsListNotEmpty(List* list);
bool CheckingForInteger(string value);
int InputValidation(int min, int max);
Node* GetNode(List*, int index);

const int MIN_NUMBER_ITEMS = 0;
const int MAX_NUMBER_ITEMS = 100;
const int MIN_VALUE_ITEMS = -100;
const int MAX_VALUE_ITEMS = 100;
const int MAX_INTEGER = 11;