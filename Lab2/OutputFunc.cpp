#include "List.h"
#include <string>

void ShowList(List* ourList)
{
	Node* current = ourList->Head;

	if (IsListEmpty(ourList))
	{
		cout << "� ����� ������ " << ourList->Size << " ���������\n";
		for (int i = 0; i < ourList->Size; i++)
		{
			cout << "[" << i << "] " << current->Data << endl;
			current = current->Next;
		}
	}
	else
	{
		cout << "��� ������ ����";
	}
}

void MenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU____________________\n";
	cout << "	|��� �������� ����, �������: 1                    |\n";
	cout << "	|��� ������� ���� � ������, �������: 2            |\n";
	cout << "	|��� ������� ���� � �����, �������: 3             |\n";
	cout << "	|��� ������� ����� ������������� ����, �������: 4 |\n";
	cout << "	|��� ������� ����� ������������ �����, �������: 5 |\n";
	cout << "	|��� ���������� ������, �������: 6                |\n";
	cout << "	|��� ��������� ������ � ������, �������: 7        |\n";
	cout << "	|��� ���������� ������ �������: 0                 |\n";
	cout << "	|_________________________________________________|\n";
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
				cout << endl << "������! ���������� ��� ���:\a ";
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
			cout << endl << "������! ���������� ��� ���: ";
			inputValue.clear();
		}
	}
}