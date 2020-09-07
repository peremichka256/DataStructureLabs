#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Next;
	Node* Prev;
};

struct List
{
	int Size;
	Node* Head;
	Node* Tail;
};

void MenuText();
List* CreatingList();
void Init(List*, int);
void AddItem(List*, int index, int newItemValue);
void Sort(List*);
void LineSearch(List*, int);
void ShowList(List*);
void DeleteList(List*);
void DeleteItem(List*, int);
bool ListNotEmpty(List*);
bool CheckingForInteger(string value);
int InputValidation(int min, int max);

const int minNumberEl = 1;
const int maxNumberEl = 100;
const int minValueEl = -100;
const int maxValueEl = 100;
const int buttonExit = 0;
const int buttonDeleteItem = 1;
const int buttonAddInBegin = 2;
const int buttonAddInEnd = 3;
const int buttonAddAfter = 4;
const int buttonAddBefore = 5;
const int buttonSort = 6;
const int buttonLineSearch = 7;
const int firstButton = 0;
const int LastButton = 7;