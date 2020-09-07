#include "BinaryTree.h"
#include "CommonFunc.h"
#include "OutputFunc.h"
#include "Treap.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		MenuText();
		cout << endl;
		button = InputValidation(0, 2);

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
				MenuBinaryTree(CreateBinaryTree());
				break;
			}
			case 2:
			{
				system("cls");
				MenuTreap(CreateTreap());
				break;
			}
		}
	}
}