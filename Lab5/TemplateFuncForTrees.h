#pragma once

template < typename NodeType >
inline NodeType* SearchForInsertOrRemove(NodeType* current, int key)
{
	if ((current->Data < key) && (current->Right == nullptr)
		|| (current->Data >= key) && (current->Left == nullptr))
	{
		return current;
	}
	else if (current->Data < key)
	{
		SearchForInsertOrRemove(current->Right, key);
	}
	else if (current->Data > key)
	{
		SearchForInsertOrRemove(current->Left, key);
	}
}

template < typename TreeType, typename NodeType >
void InsertNode(TreeType* tree, NodeType* newNode)
{
	if (tree->Root == nullptr)
	{
		tree->Root = newNode;
		tree->Root->Parent = nullptr;
	}
	else
	{
		NodeType* prevNode
			= SearchForInsertOrRemove<NodeType>(tree->Root, newNode->Data);

		if (prevNode->Data > newNode->Data)
		{
			prevNode->Left = newNode;
		}
		else if (prevNode->Data == newNode->Data)
		{
			if (prevNode->Left)
			{
				newNode->Left = prevNode->Left;
				prevNode->Left->Parent = newNode;
				prevNode->Left = nullptr;
			}

			if (prevNode->Right)
			{
				newNode->Right = prevNode->Right;
				prevNode->Right->Parent = newNode;
			}
			prevNode->Right = newNode;

			if (prevNode == tree->Root)
			{
				if (prevNode->Left)
				{
					prevNode->Left = newNode->Left;
					newNode->Left->Parent = prevNode;
					newNode->Left = nullptr;
				}
			}
		}
		else
		{
			prevNode->Right = newNode;
		}
		newNode->Parent = prevNode;
	}
}

template < typename NodeType >
NodeType* FindInTree(NodeType* current, int key)
{
	if (current->Data == key)
	{
		return current;
	}
	else if ((current->Data < key) && (current->Right != nullptr))
	{
		FindInTree(current->Right, key);
	}
	else if ((current->Data > key) && (current->Left != nullptr))
	{
		FindInTree(current->Left, key);
	}
	else
	{
		return nullptr;
	}
}

template < typename NodeType >
inline void DestroyTree(NodeType* current)
{
	if (current == nullptr)
	{
		return;
	}
	DestroyTree(current->Left);
	DestroyTree(current->Right);
	delete current;
}