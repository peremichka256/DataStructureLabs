#include "BinaryTree.h"

BinaryTree* CreateBinaryTree()
{
	BinaryTree* binaryTree = new BinaryTree;
	binaryTree->Root = nullptr;
	return binaryTree;
}

BinaryTreeNode* CreateNewNode(int data)
{
	BinaryTreeNode* newNode = new BinaryTreeNode;
	newNode->Data = data;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	return newNode;
}

bool RemoveNode(BinaryTree* binaryTree, int key)
{
	if (binaryTree->Root != nullptr)
	{
		BinaryTreeNode* removeNode 
			= SearchForInsertOrRemove<BinaryTreeNode>(binaryTree->Root, key);

		if (removeNode->Data != key)
		{
			return false;
		}
		else if ((removeNode->Left == nullptr) && (removeNode->Right == nullptr))
		{
			if (removeNode == binaryTree->Root)
			{
				delete removeNode;
				binaryTree->Root = nullptr;
			}
			else if (key < removeNode->Parent->Data)
			{
				removeNode->Parent->Left = nullptr;
				delete removeNode;
			}
			else
			{
				removeNode->Parent->Right = nullptr;
				delete removeNode;
			}
		}
		else if ((removeNode->Left == nullptr) || (removeNode->Right == nullptr))
		{
			if (removeNode == binaryTree->Root)
			{
				if (removeNode->Left == nullptr)
				{
					binaryTree->Root = removeNode->Right;
				}
				else
				{
					binaryTree->Root = removeNode->Left;
				}
				delete removeNode;
				binaryTree->Root->Parent = nullptr;
			}
			else
			{
				if (removeNode->Data < removeNode->Parent->Data)
				{
					if (removeNode->Right == nullptr)
					{
						removeNode->Parent->Left = removeNode->Left;
						removeNode->Left->Parent = removeNode->Parent;
					}
					else
					{
						removeNode->Parent->Left = removeNode->Right;
						removeNode->Right->Parent = removeNode->Parent;
					}
				}
				else
				{
					if (removeNode->Right == nullptr)
					{
						removeNode->Parent->Right = removeNode->Left;
						removeNode->Left->Parent = removeNode->Parent;
					}
					else
					{
						removeNode->Parent->Right = removeNode->Right;
						removeNode->Right->Parent = removeNode->Parent;
					}
				}
				delete removeNode;
			}
		}
		else
		{
			BinaryTreeNode* needNode = FindMin(removeNode->Right);

			if (needNode->Data >= needNode->Parent->Data)
			{
				needNode->Parent->Right = needNode->Right;

				if (needNode->Right)
				{
					needNode->Right->Parent = removeNode;
				}
			}
			else
			{
				needNode->Parent->Left = nullptr;
			}
			removeNode->Data = needNode->Data;
			delete needNode;
		}
		return true;
	}
	else
	{
		return false;
	}
}



BinaryTreeNode* FindMin(BinaryTreeNode* current)
{
	if (current->Left != nullptr)
	{
		current = FindMin(current->Left);
	}
	else
	{
		return current;
	}
}

BinaryTreeNode* FindMax(BinaryTreeNode* current)
{
	if (current->Right != nullptr)
	{
		current = FindMax(current->Right);
	}
	else
	{
		return current;
	}
}

void DeleteBinaryTree(BinaryTree* binaryTree)
{
	DestroyTree(binaryTree->Root);
	delete binaryTree;
}


bool IsNotEmpty(BinaryTree* binaryTree)
{
	if (binaryTree->Root == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}