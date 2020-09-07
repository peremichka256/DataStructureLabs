#include "Treap.h"

Treap* CreateTreap()
{
	Treap* treap = new Treap;
	treap->Root = nullptr;
	return treap;
}

Treap* Init(Treap* treap)
{
	srand(time(nullptr));
	TreapNode** array = new TreapNode*[MIN_ARRAY_SIZE];
	int minNodeData = 0;

	for (int i = 0; i < MIN_ARRAY_SIZE; i++)
	{
		TreapNode* arrayItem = new TreapNode;
		array[i] = arrayItem;
		array[i]->Priority = rand() % MAX_PRIORITY;
		minNodeData += 6;
		array[i]->Data = minNodeData;
		array[i]->Left = nullptr;
		array[i]->Right = nullptr;
	}

	for (int i = 0; i < MIN_ARRAY_SIZE - 1; i++)
	{
		for (int j = 0; j < MIN_ARRAY_SIZE - i - 1; j++)
		{
			if (array[j]->Priority > array[j + 1]->Priority)
			{
				TreapNode* temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	array[MIN_ARRAY_SIZE - 1]->Data = 50;

	for (int i = MIN_ARRAY_SIZE - 1; i > -1; i--)
	{
		InsertNode(treap, array[i]);
	}

	return treap;
}

TreapNode* FindInTreap(TreapNode* root, int key)
{
	TreapNode* findNode = FindInTree(root, key);
	return findNode;
}

void Split(int key, TreapNode* current, TreapNode*& left, TreapNode*& right)
{
	if (current == nullptr)
	{
		left = right = nullptr;
		return;
	}

	if (key < current->Data)
	{
		Split(key, current->Left, left, current->Left);
		right = current;
	}
	else
	{
		Split(key, current->Right, current->Right, right);
		left = current;
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void InsertOptimize(int key, int priority, TreapNode*& current)
{
	if (current == nullptr)
	{
		current = new TreapNode;
		current->Left = nullptr;
		current->Right = nullptr;
		current->Data = key;
		current->Priority = priority;
		return;
	}

	if (priority >= current->Priority)
	{
		TreapNode* left;
		TreapNode* right;
		Split(key, current, left, right);
		TreapNode* newTree = new TreapNode;
		newTree->Left = left;
		newTree->Right = right;
		newTree->Data = key;
		newTree->Priority = priority;
		current = newTree;
	}
	else if (key < current->Data)
	{
		InsertOptimize(key, priority, current->Left);
	}
	else
	{
		InsertOptimize(key, priority, current->Right);
	}
}

void InsertNotOptimize(TreapNode* root, int key)
{
	TreapNode* left;
	TreapNode* right;
	Split(key, root, left, right);
	TreapNode* newTree = new TreapNode;
	newTree->Left = nullptr;
	newTree->Right = nullptr;
	newTree->Data = key;
	newTree->Priority = rand() % MAX_PRIORITY;
	root = Merge(Merge(left, newTree), right);
}

bool RemoveOptimize(int key, TreapNode*& current)
{
	if (current == nullptr)
	{
		return false;
	}

	if (key == current->Data)
	{
		TreapNode* destroyedNode = current;
		current = Merge(current->Left, current->Right);
		delete destroyedNode;
	}
	else if (key < current->Data)
	{
		RemoveOptimize(key, current->Left);
	}
	else
	{
		RemoveOptimize(key, current->Right);
	}
}

bool RemoveNotOptimize(TreapNode*& root, int key)
{
	TreapNode* left;
	TreapNode* right;
	Split(key, root, left, right);
	TreapNode* destroyedTree;
	Split(key - 1, left, left, destroyedTree);

	if (destroyedTree == nullptr)
	{
		return false;
	}
	DestroyTree(destroyedTree);
	root = Merge(left, right);
}

void DeleteTreap(Treap* treap)
{
	DestroyTree(treap->Root);
	delete treap;
}