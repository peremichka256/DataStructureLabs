#include"List.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите, сколько будет в вашем листе элементов(не менее "
		<< minNumberEl << " и не более " << maxNumberEl << ") ";

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
				cout << "\nРабота окончена\n";
				DeleteList(ourList);
				return 0;
			}
			case buttonDeleteItem:
			{
				if (ListNotEmpty(ourList))
				{
					cout << "Введите номер элемента который хотите удалить ";
					DeleteItem(ourList, InputValidation(minNumberEl, ourList->Size));
				}
				system("cls");
				break;
			}
			case buttonAddInBegin:
			{
				cout << "Введите элемент который хотите добавить в начало ";
				AddItem(ourList, 1, InputValidation(minValueEl, maxValueEl));
				system("cls");
				break;
			}
			case buttonAddInEnd:
			{
				cout << "Введите элемент который хотите добавить в конец ";
				AddItem(ourList, ourList->Size + 1, InputValidation(minValueEl,maxValueEl));
				system("cls");
				break;
			}
			case buttonAddAfter:
			{
				if (ListNotEmpty(ourList))
				{
					cout << "Ведите номер элемента после которого добавится "
						<<"новый элемент ";
					int index = InputValidation(minNumberEl, ourList->Size);
					cout << "Введите новый элемент ";
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
					cout << "Ведите номер элемента перед которым добавится "
						<<"новый элемент";
					int index = InputValidation(minNumberEl, ourList->Size);
					cout << "Введите новый элемент ";
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
					cout << "Введите элемент который хотите найти в листе ";
					LineSearch(ourList, InputValidation(minValueEl, maxValueEl));
				}
				break;
			}
		}
	}
}