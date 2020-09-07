#include "DynamicArray.h"
#include "OutputFunc.h"
#include <ctime>

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	cout << "Начнём с создания массива, "
		<< "введите размерность вашего массива(не больше "
		<< MAX_LENGTH << " элементов): ";

	DynamicArray* ourDynamicArray = CreateDynamicArray();
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowArray(ourDynamicArray);
		cout << "Вот ваш массив\n";
		MenuText();
		int button = InputValidation(0, 8);

		switch (button)
		{
			case 0:
			{
				cout << "Окончание работы.\n";
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
					cout << "Введите номер элемента, который вы хотите удалить ";
					DeleteItem(ourDynamicArray, InputValidation(MIN_LENGTH,
						ourDynamicArray->Length - 1));
					system("CLS");
					break;
				}
			}
			case 3:
			{
				RecreatingMemory(ourDynamicArray);
				cout << "Введите элемент, который вы хотите добавить "
					<< "(не меньше" << MIN_ELEMENT << " и не больше " << MAX_ELEMENT << ") ";
				InsertByIndex(ourDynamicArray, 0, InputValidation(MIN_ELEMENT, MAX_ELEMENT));
				system("CLS");
				break;
			}
			case 4:
			{
				RecreatingMemory(ourDynamicArray);
				cout << "Введите элемент, который вы хотите добавить "
					<< "(не меньше" << MIN_ELEMENT << " и не больше " << MAX_ELEMENT << ") ";
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
					cout << "Ведите после какого элемента вы хотите вставить новый ";
					int index = InputValidation(MIN_LENGTH, MAX_LENGTH);
					cout << "Введите элемент, который вы хотите добавить "
						<< "(не меньше" << MIN_ELEMENT << " и не больше " << MAX_ELEMENT << ") ";
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
					cout << "Введите число, которое вы хотите найти в массиве ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					LineSearch(ourDynamicArray, key);
					break;
				}
			}
			case 8:
			{
				if (IsArrayEmpty(ourDynamicArray))
				{
					cout << "Введите число, которое вы хотите найти в массиве ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					BinarSearch(ourDynamicArray, key);
					break;
				}
			}
		}
	}
}