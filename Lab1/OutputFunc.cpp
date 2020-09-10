#include "OutputFunc.h"

bool IsArrayEmpty(DynamicArray* dynamicArray)
{
	if (dynamicArray->Length == 0)
	{
		cout << "Ur array is empty\n";
		return false;
	}
	else
	{
		return true;
	}
}

int InputValidation(int min, int max)
{
	int value;

	while (!(cin >> value) || value < min || value > max)
	{
		cin.clear();
		cin.ignore(BUFSIZ, '\n');
		cout << "Error!\n ";
	}
	return value;
}

void MenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU__________________\n";
	cout << "	|To get information about the array, press 1    |\n";
	cout << "	|To remove an item from the array, press: 2     |\n";
	cout << "	|To insert an item at the beginning, press: 3   |\n";
	cout << "	|To insert an item at the end, press: 4         |\n";
	cout << "	|To insert after a item, press: 5               |\n";
	cout << "	|To sort the array, press: 6                    |\n";
	cout << "	|For line search in array, press: 7             |\n";
	cout << "	|For binary search in array, press: 8           |\n";
	cout << "	|To complete the work, press: 0                 |\n";
	cout << "	|_______________________________________________|\n";
	cout << "	\n";
}

void ShowArray(DynamicArray* dynamicArray)
{
	if (IsArrayEmpty(dynamicArray))
	{
		for (int i = 0; i < dynamicArray->Length; i++)
		{
			cout << "[" << i << "] " << dynamicArray->Array[i] << endl;
		}
	}
}