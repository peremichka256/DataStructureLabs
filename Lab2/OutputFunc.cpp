#include "List.h"
#include <string>

void ShowList(List* ourList)
{
	Node* current = ourList->Head;

	if (IsListEmpty(ourList))
	{
		cout << "В вашем списке " << ourList->Size << " элементов\n";
		for (int i = 0; i < ourList->Size; i++)
		{
			cout << "[" << i << "] " << current->Data << endl;
			current = current->Next;
		}
	}
	else
	{
		cout << "Ваш список пуст";
	}
}

void MenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU____________________\n";
	cout << "	|Для удаления узла, нажмите: 1                    |\n";
	cout << "	|Для вставки узла в начало, нажмите: 2            |\n";
	cout << "	|Для вставки узла в конец, нажмите: 3             |\n";
	cout << "	|Для вставки после определенного узла, нажмите: 4 |\n";
	cout << "	|Для вставки перед определенным узлом, нажмите: 5 |\n";
	cout << "	|Для сортировки списка, нажмите: 6                |\n";
	cout << "	|Для линейного поиска в списке, нажмите: 7        |\n";
	cout << "	|Для завершения работы нажмите: 0                 |\n";
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
				cout << endl << "Ошибка! Попробуйте еще раз:\a ";
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
			cout << endl << "Ошибка! Попробуйте еще раз: ";
			inputValue.clear();
		}
	}
}