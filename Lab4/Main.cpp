#include "CommonFunc.h"
#include "HashTable.h"
#include "OutputInputFunc.h"
#include "Windows.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		MainMenuText();
		int button = InputValidation(0, 2);

		switch (button)
		{
			case 0:
			{
				cout << "\nРабота окончена\n";
				return 0;
			}
			case 1:
			{
				system("cls");
				MenuHashTable(CreateTable(MIN_HASHTABLE_SIZE));
				break;
			}
			case 2:
			{
				system("cls");
				MenuDictionary(CreateDictionary());
				break;
			}
		}
	}
}