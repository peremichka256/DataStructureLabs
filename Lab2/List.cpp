#include"List.h"
#include<ctime>
#include<string>

void LineSearch(List* ourList, int searchItem)
{
	int i = 1;
	Node* current = new Node;
	current = ourList->Head;

	for (i = 1; i <= ourList->Size; i++)
	{
		if (current->Data == searchItem)
		{
			cout << "Элемент " << i << " имеет искомое значение";
		}
		current = current->Next;
	}
}

void Init(List* ourList, int itemNumber)
{
	srand(time(nullptr));

	for (int i = 1;  i <= itemNumber; i++)
	{
		if (i == 1)
		{
			Node* newItem = new Node;
			newItem->Data = rand() % maxValueEl * 2 - maxValueEl;
			ourList->Head = newItem;
			ourList->Tail = newItem;
			newItem->Next = newItem->Prev = nullptr;
		}
		else
		{
			Node* newItem = new Node;								
			newItem->Data = rand() % maxValueEl * 2 - maxValueEl;
			ourList->Head->Prev = newItem;
			newItem->Next = ourList->Head;
			ourList->Head = newItem;
			newItem->Prev = nullptr;
		}
		ourList->Size++;
	}
}

void DeleteItem(List* ourList, int index)
{
	int i=1;

	if (ourList->Size)
	{
		if (ourList->Head->Prev == ourList->Head->Next)
		{
			delete ourList->Head;
			ourList->Head = ourList->Tail = nullptr;
		}
		else
		{
			Node* current = ourList->Head;

			while (i != index)
			{
				for (i = 1; i < index; i++)
				{
					current = current->Next;
				}
			} 

			if (current->Prev == nullptr)
			{
				ourList->Head = ourList->Head->Next;
				delete ourList->Head->Prev;
				ourList->Head->Prev = nullptr;
			}
			else if (current->Next == nullptr)
			{
				ourList->Tail = ourList->Tail->Prev;
				delete ourList->Tail->Next;
				ourList->Tail->Next = nullptr;
			}
			else
			{
				current->Prev->Next = current->Next;
				current->Next->Prev = current->Prev;
				delete current;
			}
		}
		ourList->Size--;
	}
	else cout << "У вас нет элементов";
}

void DeleteList(List* list)
{
	if (list && list->Head)
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

void AddItem(List* ourList, int index, int newItemValue)
{
	Node* newItem = new Node;
	newItem->Data = newItemValue;

	if (ourList->Size == 0)
	{
		ourList->Head = newItem;
		ourList->Tail = newItem;
		newItem->Next = newItem->Prev = nullptr;
	}
	else if ((index == 1)||(index==0))
	{
		ourList->Head->Prev = newItem;
		newItem->Next = ourList->Head;
		ourList->Head = newItem;
		newItem->Prev = nullptr;
	}
	else if (index == ourList->Size+1)
	{
		ourList->Tail->Next = newItem;
		newItem->Prev = ourList->Tail;
		ourList->Tail = newItem;
		newItem->Next = nullptr;
	}
	else
	{
		Node* current = new Node;
		current = ourList->Head;

		for (int i = 1; i <= index; i++)
		{
			if (i == index)
			{
				newItem->Next = current;
				newItem->Prev = current->Prev;
				current->Prev->Next = newItem;
				current->Prev = newItem;
			}
			current = current->Next;
		}
	}
	ourList->Size++;
}

List* CreatingList()
{
	List* newList = new List;
	newList->Size = 0;
	newList->Head = newList->Tail = nullptr;
	return newList;
}

void ShowList(List* ourList)
{
	Node* current = new Node;
	current = ourList->Head;

	cout << "В нашем листе " << ourList->Size << " элементов\n";

	if (ourList->Size)
	{
		for (int i = 1; i <= ourList->Size; i++)
		{
			cout << "[" << i << "] " << current->Data << endl;
			current = current->Next;
		}
	}
}

void MenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU____________________\n";
	cout << "	|Для удаления узла, нажмите: "
		<<buttonDeleteItem<<"                    |\n";
	cout << "	|Для вставки узла в начало, нажмите: "
		<<buttonAddInBegin<<"            |\n";
	cout << "	|Для вставки узла в конец, нажмите: "
		<<buttonAddInEnd<<"             |\n";
	cout << "	|Для вставки после определенного узла, нажмите: "
		<<buttonAddAfter<<" |\n";
	cout << "	|Для вставки перед определенным узлом, нажмите: "
		<<buttonAddBefore<<" |\n";
	cout << "	|Для сортировки списка, нажмите: "
		<<buttonSort<<"                |\n";
	cout << "	|Для линейного поиска в списке, нажмите: "
		<<buttonLineSearch<<"        |\n";
	cout << "	|Для завершения работы нажмите: "
		<<buttonExit<<"                 |\n";
	cout << "	|_________________________________________________|\n";
	cout << "	\n";
}

void Sort(List* ourList)
{
	if (ListNotEmpty(ourList))
	{
		Node* current = new Node;
		current = ourList->Head;

		for (int i = 1; i <= ourList->Size; i++)
		{
			current = ourList->Head;

			while (current && current->Next)
			{
				if (current->Data > current->Next->Data)
				{
					Node* temp;
					if (current == ourList->Head)
					{
						ourList->Head = current->Next;
						ourList->Head->Prev = nullptr;
					}
					else
					{
						current->Prev->Next = current->Next;
						current->Next->Prev = current->Prev;
					}
					temp = current->Next->Next;
					current->Next->Next = current;
					current->Prev = current->Next;
					if (current->Next != ourList->Tail)
					{
						current->Next = temp;
						temp->Prev = current;
					}
					else
					{
						ourList->Tail = current;
						ourList->Tail->Next = nullptr;
					}
				}
				current = current->Next;
			}
		}
	}
}

bool ListNotEmpty(List* List)
{
	if (List->Size == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CheckingForInteger(string value)
{
	int size = value.length();

	if (isdigit(value[0]) || value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit(value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int InputValidation(int min, int max)
{
	string inputValue;
	int outputValue;
	
	while (true)
	{
		getline(cin, inputValue);

		if (CheckingForInteger(inputValue) == false)
		{
			cout << endl << "Ошибка! Введите цифры. ";
			inputValue.clear();
		}
		else
		{
			outputValue = stoi(inputValue);

			if ((outputValue > max) || (outputValue < min))
			{
				cout << "Похоже вы вводите число вне доступного диапазона, "
					<<"попробуйте заново. ";
			}
			else
			{
				return outputValue;
			}
		}
	}
}