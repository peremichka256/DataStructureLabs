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

	DynamicArray* ourDynamicArray = CreateDynamicArray();
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowArray(ourDynamicArray);
		cout << "��� ��� ������\n";
		MenuText();
		int button = InputValidation(0, 8);

		switch (button)
		{
			case 0:
			{
				cout << "��������� ������.\n";
				DeleteDynamicArray(ourDynamicArray);
				return 0;
			}
			case 1:
			{
				system("CLS");
				DefineFieldArray(ourDynamicArray);
				break;
			}
			case 2:
			{
				if (IsArrayEmpty(ourDynamicArray))
				{
					cout << "������� ����� ��������, ������� �� ������ ������� ";
					DeleteItem(ourDynamicArray, InputValidation(MIN_LENGTH,
						ourDynamicArray->Length - 1));
					system("CLS");
					break;
				}
			}
			case 3:
			{
				RecreatingMemory(ourDynamicArray);
				cout << "������� �������, ������� �� ������ �������� "
					<< "(�� ������" << MIN_ELEMENT << " � �� ������ " << MAX_ELEMENT << ") ";
				InsertByIndex(ourDynamicArray, 0, InputValidation(MIN_ELEMENT, MAX_ELEMENT));
				system("CLS");
				break;
			}
			case 4:
			{
				RecreatingMemory(ourDynamicArray);
				cout << "������� �������, ������� �� ������ �������� "
					<< "(�� ������" << MIN_ELEMENT << " � �� ������ " << MAX_ELEMENT << ") ";
				InsertByIndex(ourDynamicArray, ourDynamicArray->Length,
					InputValidation(MIN_ELEMENT, MAX_ELEMENT));
				system("CLS");
				break;
			}
			case 5:
			{
				if(IsArrayEmpty(ourDynamicArray))
				{
					RecreatingMemory(ourDynamicArray);
					cout << "������ ����� ������ �������� �� ������ �������� ����� ";
					int index = InputValidation(MIN_LENGTH, MAX_LENGTH);
					cout << "������� �������, ������� �� ������ �������� "
						<< "(�� ������" << MIN_ELEMENT << " � �� ������ " << MAX_ELEMENT << ") ";
					InsertByIndex(ourDynamicArray, index+1,
						InputValidation(MIN_ELEMENT, MAX_ELEMENT));
					system("CLS");
					break;
				}
				break;
			}
			case 6:
			{
				if (IsArrayEmpty(ourDynamicArray))
				{
					system("CLS");
					Sort(ourDynamicArray);
					break;
				}
			}
			case 7:
			{
				if (IsArrayEmpty(ourDynamicArray))
				{
					cout << "������� �����, ������� �� ������ ����� � ������� ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					LineSearch(ourDynamicArray, key);
					break;
				}
			}
			case 8:
			{
				if (IsArrayEmpty(ourDynamicArray))
				{
					cout << "������� �����, ������� �� ������ ����� � ������� ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					BinarSearch(ourDynamicArray, key);
					break;
				}
			}
		}
	}
}