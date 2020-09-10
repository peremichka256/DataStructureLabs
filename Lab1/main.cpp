#include "DynamicArray.h"
#include "OutputFunc.h"
#include <ctime>

int main()
{
	srand(time(nullptr));
	cout << "Start by creating an array, "
		<< "enter the dimension of your array(no more than "
		<< MAX_LENGTH << " elements): ";

	DynamicArray* dynamicArray = CreateDynamicArray();
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowArray(dynamicArray);
		cout << "Here is ur array\n";
		MenuText();
		int button = InputValidation(0, 8);

		switch (button)
		{
			case 0:
			{
				cout << "Work is completing.\n";
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
					cout << "Enter the number of the item you want to delete ";
					DeleteItem(dynamicArray, InputValidation(MIN_LENGTH,
						dynamicArray->Length - 1));
					system("CLS");
					break;
				}
			}
			case 3:
			{
				//Insert at the beginning
				RecreatingMemory(dynamicArray);
				cout << "Enter the item you want to insert "
					<< "(not less than" << MIN_ELEMENT << " and not more than " << MAX_ELEMENT << ") ";
				InsertByIndex(dynamicArray, 0, InputValidation(MIN_ELEMENT, MAX_ELEMENT));
				system("CLS");
				break;
			}
			case 4:
			{
				//Insert at the end
				RecreatingMemory(dynamicArray);
				cout << "Enter the item you want to insert "
					<< "(not less than" << MIN_ELEMENT << " and not more than " << MAX_ELEMENT << ") ";
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
					cout << "Enter the item after which you want to insert the new item ";
					int index = InputValidation(MIN_LENGTH, MAX_LENGTH);
					cout << "Enter the item you want to insert "
						<< "(not less than" << MIN_ELEMENT << " and not more thanå " << MAX_ELEMENT << ") ";
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
					cout << "Enter the number you want to find in the array ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					LineSearch(dynamicArray, key);
					break;
				}
			}
			case 8:
			{
				if (IsArrayEmpty(dynamicArray))
				{
					cout << "Enter the number you want to find in the array ";
					int key = InputValidation(MIN_ELEMENT, MAX_ELEMENT);
					BinarySearch(dynamicArray, key);
					break;
				}
			}
		}
	}
}