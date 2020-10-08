#include "List.h"
#include <ctime>

void Initialization(List* list, int itemNumber)
{
	srand(time(nullptr));

	for (int i = 0;  i < itemNumber; i++)
	{
		Node* newItem = new Node;
		newItem->Data = rand() % MAX_VALUE_ITEMS * 2 - MAX_VALUE_ITEMS;

		if (i == 0)
		{
			list->Head = newItem;
			list->Tail = newItem;
			newItem->Next = newItem->Prev = nullptr;
		}
		else
		{							
			list->Head->Prev = newItem;
			newItem->Next = list->Head;
			list->Head = newItem;
			newItem->Prev = nullptr;
		}
		list->Size++;
	}
}

void DeleteItem(List* list, int index)
{
	if (IsListNotEmpty(list))
	{
		if (list->Head->Prev == list->Head->Next)
		{
			delete list->Head;
			list->Head = list->Tail = nullptr;
		}
		else if (index == 0)
		{
			list->Head = list->Head->Next;
			delete list->Head->Prev;
			list->Head->Prev = nullptr;
		}
		else if (index == list->Size - 1)
		{
			list->Tail = list->Tail->Prev;
			delete list->Tail->Next;
			list->Tail->Next = nullptr;
		}
		else
		{
			Node* current = GetNode(list, index);

			current->Prev->Next = current->Next;
			current->Next->Prev = current->Prev;
			delete current;
		}
		list->Size--;
	}
}

void DeleteList(List* list)
{
	if (IsListNotEmpty)
	{
		Node* current = list->Head;

		while (current && current->Next)
		{
			current = current->Next;
			delete current->Prev;
		}
		delete list->Tail;
		delete list;
		list = nullptr;
	}
}

void AddItem(List* list, int index, int newItemValue)
{
	Node* newItem = new Node;
	newItem->Data = newItemValue;

	if (list->Size == 0)
	{
		list->Head = newItem;
		list->Tail = newItem;
		newItem->Next = newItem->Prev = nullptr;
	}
	else if (index == 0)
	{
		list->Head->Prev = newItem;
		newItem->Next = list->Head;
		list->Head = newItem;
		newItem->Prev = nullptr;
	}
	else if (index == list->Size)
	{
		list->Tail->Next = newItem;
		newItem->Prev = list->Tail;
		list->Tail = newItem;
		newItem->Next = nullptr;
	}
	else 
	{
		Node* current = GetNode(list, index);

		newItem->Next = current;
		newItem->Prev = current->Prev;
		current->Prev->Next = newItem;
		current->Prev = newItem;
	}
	list->Size++;
}

List* CreatingList()
{
	List* newList = new List;
	newList->Size = 0;
	newList->Head = newList->Tail = nullptr;
	return newList;
}

void Sort(List* list)
{
	if (IsListNotEmpty(list))
	{
		for (int i = 0; i < list->Size; i++)
		{
			Node* current = list->Head;

			while (current && current->Next)
			{
				if (current->Data > current->Next->Data)
				{
					Node* temp;

					if (current == list->Head)
					{
						list->Head = current->Next;
						list->Head->Prev = nullptr;
					}
					else
					{
						current->Prev->Next = current->Next;
						current->Next->Prev = current->Prev;
					}
					temp = current->Next->Next;
					current->Next->Next = current;
					current->Prev = current->Next;

					if (current->Next != list->Tail)
					{
						current->Next = temp;
						temp->Prev = current;
					}
					else
					{
						list->Tail = current;
						list->Tail->Next = nullptr;
					}
				}
				current = current->Next;
			}
		}
	}
}

bool IsListNotEmpty(List* list)
{
	if (list->Size == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Node* GetNode(List* list, int index)
{
	Node* current = new Node;

	if (index < list->Size / 2)
	{
		current = list->Head;

		for (int i = 0; i < index; i++)
		{
			current = current->Next;
		}
	}
	else
	{
		current = list->Tail;

		for (int i = list->Size - 1; i > index; i--)
		{
			current = current->Prev;
		}
	}
	return current;
}

int LineSearch(List* list, int searchItemValue)
{
	if (IsListNotEmpty(list))
	{
		Node* current = list->Head;

		for (int i = 0; i < list->Size; i++)
		{
			if (current->Data == searchItemValue)
			{
				return i;
			}
			current = current->Next;
		}
		return -1;
	}
}