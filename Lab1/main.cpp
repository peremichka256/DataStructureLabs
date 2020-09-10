#include "DynamicArray.h"
#include "OutputFunc.h"
#include <ctime>

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	cout << "����� � �������� �������, "
		<< "������� ����������� ������ �������(�� ������ "
		<< MAX_LENGTH << " ���������): ";

	DynamicArray* dynamicArray = CreateDynamicArray();
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowArray(dynamicArray);
		cout << "��� ��� ������\n";
		MenuText();
		int button = InputValidation(0, 8);

		switch (button)
		{
			case 0:
			{
				cout << "��������� ������.\n";
				DeleteDynamicArray(dynamicArray);
				return 0;
			}
			case 1:
			{
				system("CLS");
				DefineFieldArray(dynamicArray);
				break;
			}
			case 2:
			{
				if (IsArrayEmpty(dynamicArray))
				{
					cout << "������� ����� ��������, ������� �� ������ ������� ";
					DeleteItem(dynamicArray, InputValidation(MIN_LENGTH,
						dynamicArray->Length - 1));
					system("CLS");
					break;
				}
			}
			case 3:
			{
				RecreatingMemory(dynamicArray);
				cout << "������� �������, ������� �� ������ �������� "
					<< "(�� ������" << MIN_ELEMENT << " � �� ������ " << MAX_ELEMENT << ") ";
				InsertByIndex(dynamicArray, 0, InputValidation(MIN_ELEMENT, MAX_ELEMENT));
				system("CLS");
				break;
			}
			case 4:
			{
				RecreatingMemory(dynamicArray);
				cout << "������� �������, ������� �� ������ �������� "
					<< "(�� ������" << MIN_ELEMENT << " � �� ������ " << MAX_ELEMENT << ") ";
				InsertByIndex(dynamicArray, dynamicArray->Length,
					InputValidation(MIN_ELEMENT, MAX_ELEMENT));
				system("CLS");
				break;
			}
			case 5:
			{
				if(IsArrayEmpty(dynamicArray))
				{
					RecreatingMemory(dynamicArray);
					cout << "������ ����� ������ �������� �� ������ �������� ����� ";
					int index = InputValidation(MIN_LENGTH, MAX_LENGTH);
					cout << "������� �������, ������� �� ������ �������� "
						<< "(�� ������" << MIN_ELEMENT << " � �� ������ " << MAX_ELEMENT << ") ";
					InsertByIndex(dynamicArray, index+1,
						InputValidation(MIN_ELEMENT, MAX_ELEMENT));
					system("CLS");
					break;
				}
				break;
			}
			case 6:
			{
				if (IsArrayEmpty(dynamicArray))
				{
					system("CLS");
					Sort(dynamicArray);
					break;
				}
			}
			case 7:
			{
				if (IsArrayEmpty(dynamicArray))
				{
					cout << "������� �����, ������� �� ������ ����� � ������� ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					LineSearch(dynamicArray, key);
					break;
				}
			}
			case 8:
			{
				if (IsArrayEmpty(dynamicArray))
				{
					cout << "������� �����, ������� �� ������ ����� � ������� ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					BinarSearch(dynamicArray, key);
					break;
				}
			}
		}
	}
}