#include "List.h"

int main()
{
	cout << "Enter the dimension of your List(not less than "
		<< MIN_NUMBER_ITEMS << " and no more than " << MAX_NUMBER_ITEMS << ") ";
	List* list = CreatingList();
	Initialization(list, InputValidation(MIN_NUMBER_ITEMS, MAX_NUMBER_ITEMS));
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowList(list);
		PrintMenuText();
		int button = InputValidation(0, 7);

		switch (button)
		{
			case 0:
			{
				cout << "\nWork is completing.\n";
				DeleteList(list);
				return 0;
			}
			case 1:
			{
				cout << "Enter the number of the node you want to delete ";
				int indexToDelete = InputValidation(MIN_NUMBER_ITEMS,
					list->Size);
				DeleteItem(list, indexToDelete);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "Enter the number value of the node you want to insert"
					<< "at the beginig ";
				AddItem(list, 0, InputValidation(MIN_VALUE_ITEMS,
					MAX_VALUE_ITEMS));
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Enter the number value of the node you want to insert "
					<< "at the end ";
				AddItem(list, list->Size, 
					InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS));
				system("cls");
				break;
			}
			case 4:
			{
				if (IsListNotEmpty(list))
				{
					cout << "Enter the number of the node after which the new "
						<< "node is insert ";
					int index = InputValidation(MIN_NUMBER_ITEMS, list->Size);
					cout << "Enter the new node value ";
					int value = InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS);
					AddItem(list, index + 1, value);
				}
				system("cls");
				break;
			}
			case 5:
			{
				if (IsListNotEmpty(list))
				{
					cout << "Enter the number of the node before which the new "
						<< "node is insert ";
					int index = InputValidation(MIN_NUMBER_ITEMS, list->Size);
					cout << "Enter the new node value ";
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
				cout << "Enter the node value that you want to find "
					<< "in the list ";
				int searchItem = InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS);
				int foundItemIndex = LineSearch(list, searchItem);

				if (foundItemIndex == -1)
				{
					cout << "This value was not found\n";
				}
				else
				{
					cout << foundItemIndex << "s item"
						<< " is desired.\n ";
				}
				break;
			}
		}
	}
}