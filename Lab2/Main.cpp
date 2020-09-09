#include "List.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "�������, ������� ����� � ����� ����� ���������(�� ����� "
		<< MIN_NUMBER_ITEMS << " � �� ����� " << MAX_NUMBER_ITEMS << ") ";
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
				cout << "\n������ ��������\n";
				DeleteList(list);
				return 0;
			}
			case 1:
			{
				cout << "������� ����� �������� ������� ������ ������� ";
				int indexToDelete = InputValidation(MIN_NUMBER_ITEMS,
					list->Size);
				DeleteItem(list, indexToDelete);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "������� ������� ������� ������ �������� � ������ ";
				AddItem(list, 0, InputValidation(MIN_VALUE_ITEMS,
					MAX_VALUE_ITEMS));
				system("cls");
				break;
			}
			case 3:
			{
				cout << "������� ������� ������� ������ �������� � ����� ";
				AddItem(list, list->Size, 
					InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS));
				system("cls");
				break;
			}
			case 4:
			{
				if (IsListEmpty(list))
				{
					cout << "������ ����� �������� ����� �������� ��������� "
						<<"����� ������� ";
					int index = InputValidation(MIN_NUMBER_ITEMS, list->Size);
					cout << "������� ����� ������� ";
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
					cout << "������ ����� �������� ����� ������� ��������� "
						<<"����� ������� ";
					int index = InputValidation(MIN_NUMBER_ITEMS, list->Size);
					cout << "������� ����� ������� ";
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
				cout << "������� ������� ������� ������ ����� � ����� ";
				int searchItem = InputValidation(MIN_VALUE_ITEMS, MAX_VALUE_ITEMS);
				int foundItemIndex = LineSearch(list, searchItem);

				if (foundItemIndex == -1)
				{
					cout << "� ����� ������ ��� ����� ��������\n";
				}
				else
				{
					cout << foundItemIndex << "-� �������"
						<< " � ������ ������������� �������� ��������.\n ";
				}
				break;
			}
		}
	}
}