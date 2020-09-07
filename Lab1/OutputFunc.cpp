#include "OutputFunc.h"

bool IsArrayEmpty(DynamicArray* dynamicArray)
{
	if (dynamicArray->Length == 0)
	{
		cout << "В вашем массиве нет элементов\n";
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
		cout << "Ошибка!\n ";
	}
	return value;
}

void MenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU_______________________ \n";
	cout << "	|Для определения полей массива, нажмите: 1           |\n";
	cout << "	|Для удаление элемента из массива, нажмите: 2        |\n";
	cout << "	|Для вставки элемента в начало, нажмите: 3           |\n";
	cout << "	|Для вставки элемента в конец, нажмите: 4            |\n";
	cout << "	|Для вставки после определенного элемента, нажмите: 5|\n";
	cout << "	|Для сортировки массива, нажмите: 6                  |\n";
	cout << "	|Для линейного поиска в массиве, нажмите: 7          |\n";
	cout << "	|Для бинарного поиска в массиве, нажмите: 8          |\n";
	cout << "	|Для завершения работы нажмите: 0                    |\n";
	cout << "	|____________________________________________________|\n";
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