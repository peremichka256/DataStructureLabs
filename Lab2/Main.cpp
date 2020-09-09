#include "List.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите, сколько будет в вашем листе элементов(не менее "
		<< MIN_NUMBER_ITEMS << " и не более " << MAX_NUMBER_ITEMS << ") ";
	List* list = CreatingList();
	Initialization(list, InputValidation(MIN_NUMBER_ITEMS, MAX_NUMBER_ITEMS));
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowList(list);
		MenuText();
		int button = InputValidation(0, 7);

		switch (button)
		{
			case 0:
			{
				cout << "\nРабота окончена\n";
				DeleteList(list);
				return 0;
			}
			case 1:
			{
				cout << "Введите номер элемента который хотите удалить ";
				int indexToDelete = InputValidation(MIN_NUMBER_ITEMS,
					list->Size);
				DeleteItem(list, indexToDelete);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "Введите элемент который хотите добавить в начало ";
				AddItem(list, 0, InputValidation(MIN_VALUE_ITEMS,
					MAX_VALUE_ITEMS));
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Введите элемент который хотите добавить в конец ";
				AddItem(list, list->Size, 
					InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS));
				system("cls");
				break;
			}
			case 4:
			{
				if (IsListEmpty(list))
				{
					cout << "Ведите номер элемента после которого добавится "
						<<"новый элемент ";
					int index = InputValidation(MIN_NUMBER_ITEMS, list->Size);
					cout << "Введите новый элемент ";
					int value = InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS);
					AddItem(list, index + 1, value);
				}
				system("cls");
				break;
			}
			case 5:
			{
				if (IsListEmpty(list))
				{
					cout << "Ведите номер элемента перед которым добавится "
						<<"новый элемент ";
					int index = InputValidation(MIN_NUMBER_ITEMS, list->Size);
					cout << "Введите новый элемент ";
					AddItem(list, index, InputValidation(MIN_VALUE_ITEMS,
						MAX_VALUE_ITEMS));
				}
				system("cls");
				break;
			}
			case 6:
			{
				Sort(list);
				system("cls");
				break;
			}
			case 7:
			{
				cout << "Введите элемент который хотите найти в листе ";
				int searchItem = InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS);
				int foundItemIndex = LineSearch(list, searchItem);

				if (foundItemIndex == -1)
				{
					cout << "В вашем списке нет этого элемента\n";
				}
				else
				{
					cout << foundItemIndex << "-й элемент"
						<< " в списке соответствует искомому значению.\n ";
				}
				break;
			}
		}
	}
}