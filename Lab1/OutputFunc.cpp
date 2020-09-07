#include "OutputFunc.h"

bool IsArrayEmpty(DynamicArray* dynamicArray)
{
	if (dynamicArray->Length == 0)
	{
		cout << "� ����� ������� ��� ���������\n";
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
		cout << "������!\n ";
	}
	return value;
}

void MenuText()
{
	cout << "	\n";
	cout << "	 _________________________MENU_______________________ \n";
	cout << "	|��� ����������� ����� �������, �������: 1           |\n";
	cout << "	|��� �������� �������� �� �������, �������: 2        |\n";
	cout << "	|��� ������� �������� � ������, �������: 3           |\n";
	cout << "	|��� ������� �������� � �����, �������: 4            |\n";
	cout << "	|��� ������� ����� ������������� ��������, �������: 5|\n";
	cout << "	|��� ���������� �������, �������: 6                  |\n";
	cout << "	|��� ��������� ������ � �������, �������: 7          |\n";
	cout << "	|��� ��������� ������ � �������, �������: 8          |\n";
	cout << "	|��� ���������� ������ �������: 0                    |\n";
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