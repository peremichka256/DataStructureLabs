#include"List.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "�������, ������� ����� � ����� ����� ���������(�� ����� "
		<< minNumberEl << " � �� ����� " << maxNumberEl << ") ";

	List* ourList = CreatingList();
	Init(ourList, InputValidation(minNumberEl, maxNumberEl));
	
	int button;
	bool exitFromWhile = true;

	while (exitFromWhile)
	{
		ShowList(ourList);
		MenuText();
		button = InputValidation(firstButton, LastButton);

		switch (button)
		{
			case buttonExit:
			{
				cout << "\n������ ��������\n";
				DeleteList(ourList);
				return 0;
			}
			case buttonDeleteItem:
			{
				if (ListNotEmpty(ourList))
				{
					cout << "������� ����� �������� ������� ������ ������� ";
					DeleteItem(ourList, InputValidation(minNumberEl, ourList->Size));
				}
				system("cls");
				break;
			}
			case buttonAddInBegin:
			{
				cout << "������� ������� ������� ������ �������� � ������ ";
				AddItem(ourList, 1, InputValidation(minValueEl, maxValueEl));
				system("cls");
				break;
			}
			case buttonAddInEnd:
			{
				cout << "������� ������� ������� ������ �������� � ����� ";
				AddItem(ourList, ourList->Size + 1, InputValidation(minValueEl,maxValueEl));
				system("cls");
				break;
			}
			case buttonAddAfter:
			{
				if (ListNotEmpty(ourList))
				{
					cout << "������ ����� �������� ����� �������� ��������� "
						<<"����� ������� ";
					int index = InputValidation(minNumberEl, ourList->Size);
					cout << "������� ����� ������� ";
					AddItem(ourList, index + 1, InputValidation(minValueEl,
						maxValueEl));
				}
				system("cls");
				break;
			}
			case buttonAddBefore:
			{
				if (ListNotEmpty(ourList))
				{
					cout << "������ ����� �������� ����� ������� ��������� "
						<<"����� �������";
					int index = InputValidation(minNumberEl, ourList->Size);
					cout << "������� ����� ������� ";
					AddItem(ourList, index, InputValidation(minValueEl,
						maxValueEl));
				}
				system("cls");
				break;
			}
			case buttonSort:
			{
				Sort(ourList);
				system("cls");
				break;
			}
			case buttonLineSearch:
			{
				if (ListNotEmpty(ourList))
				{
					cout << "������� ������� ������� ������ ����� � ����� ";
					LineSearch(ourList, InputValidation(minValueEl, maxValueEl));
				}
				break;
			}
		}
	}
}