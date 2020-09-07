#pragma once
#include "BinaryTreeNode.h"
#include "TemplateFuncForTrees.h"

struct BinaryTree
{
	BinaryTreeNode* Root;
};

BinaryTree* CreateBinaryTree();
BinaryTreeNode* CreateNewNode(int data);
bool RemoveNode(BinaryTree*, int);
BinaryTreeNode* FindMin(BinaryTreeNode*);
BinaryTreeNode* FindMax(BinaryTreeNode*);
void DeleteBinaryTree(BinaryTree* binaryTree);
bool IsNotEmpty(BinaryTree*);