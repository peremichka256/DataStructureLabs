#include "List.h"
#include <string>

void ShowList(List* ourList)
{
	Node* current = ourList->Head;

	if (IsListEmpty(ourList))
	{
		cout <<  ourList->Size << " items at ur lsit.\n";
		for (int i = 0; i < ourList->Size; i++)
		{
			cout << "[" << i << "] " << current->Data << endl;
			current = current->Next;
		}
	}
	else
	{
		cout << "Ur list is empty.";
	}
}

void PrintMenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU____________________\n";
	cout << "	|To delete node from the list, press: 1          |\n";
	cout << "	|To insert an node at the list beginnig, press: 2|\n";
	cout << "	|To insert an node at the list end, press: 3     |\n";
	cout << "	|To insert after a certain node, click: 4        |\n";
	cout << "	|To insert before a certain node, click: 5       |\n";
	cout << "	|To sort the list, press: 6                      |\n";
	cout << "	|To linear search in the list, press: 7          |\n";
	cout << "	|To complete the work, press: 0                  |\n";
	cout << "	|________________________________________________|\n";
	cout << "	\n";
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

	while (true)
	{
		getline(cin, inputValue);

		if (inputValue.length() <= MAX_INTEGER)
		{
			int outputValue;

			if (CheckingForInteger(inputValue) == false
				|| stoll(inputValue) < min
				|| stoll(inputValue) > max)
			{
				cout << endl << "Error! Try again:\a ";
				inputValue.clear();
			}
			else
			{
				outputValue = stoll(inputValue);
				return outputValue;
			}
		}
		else
		{
			cout << endl << "Error! Try again: ";
			inputValue.clear();
		}
	}
}