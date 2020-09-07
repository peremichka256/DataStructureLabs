#pragma once
#include "TreapNode.h"
#include "TemplateFuncForTrees.h"
#include <iostream>
#include <ctime>

struct Treap
{
	TreapNode* Root;
};

Treap* CreateTreap();
Treap* Init(Treap*);
TreapNode* FindInTreap(TreapNode*, int);
void Split(int, TreapNode*, TreapNode*& left, TreapNode*& right);
TreapNode* Merge(TreapNode* left, TreapNode* right);
void InsertOptimize(int, int, TreapNode*&);
void InsertNotOptimize(TreapNode*, int);
bool RemoveOptimize(int, TreapNode*&);
bool RemoveNotOptimize(TreapNode*&, int);
void DeleteTreap(Treap*);

const int MIN_ARRAY_SIZE = 16;
const int MAX_PRIORITY = 100;