#pragma once
#include "BinaryTree.h"
#include "TemplateFuncForTrees.h"
#include "Treap.h"

void MenuText();
//�������� ������ ������
void PrintBinaryTree(BinaryTreeNode* current, int level);
void MenuBinaryTreeText();
int MenuBinaryTree(BinaryTree* binaryTree);
//��������� ������
int MenuTreap(Treap* Treap);
void PrintTreap(TreapNode* current, int level);
void MenuTreapText();

