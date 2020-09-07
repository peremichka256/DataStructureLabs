#include "OutputFunc.h"
#include "CommonFunc.h"

void MenuText()
{
	cout << "_______________________MENU_______________________\n";
	cout << "|Для завершения работы нажмите 0.                |\n";
	cout << "|Для работы с бинарным деревом поиска нажмите 1. |\n";
	cout << "|Для работы с декартовым деревом нажмите 2.      |\n";
	cout << "|________________________________________________|\n";
}

void MenuBinaryTreeText()
{
	cout << "__________________________MENU_________________________\n";
	cout << "|Для завершения работы с деревом нажмите 0.           |\n";
	cout << "|Для добавления элемента в бинарное дерево нажмите 1. |\n";
	cout << "|Для удаления элемента из бинарного дерева нажмите 2. |\n";
	cout << "|Для поиска элемента в бинарном дереве нажмите 3.     |\n";
	cout << "|Для поиска максимума в бинарном дереве нажмите 4.    |\n";
	cout << "|Для поиска минимума в бинарном дереве нажмите 5.     |\n";
	cout << "|_____________________________________________________|\n";
	cout << endl;
}

void MenuTreapText()
{
	cout << "____________________________MENU___________________________\n";
	cout << "|Для завершения работы с деревом нажмите 0.               |\n";
	cout << "|Для оптимизированного добавления элемента в нажмите 1.   |\n";
	cout << "|Для неоптимизированного добавления элемента в нажмите 2. |\n";
	cout << "|Для оптимизированного удаления элемента нажмите 3.       |\n";
	cout << "|Для неоптимизированного удаления элемента нажмите 4.     |\n";
	cout << "|Для поиска элемента нажмите 5.                           |\n";
	cout << "|_________________________________________________________|\n";
	cout << endl;
}

int MenuBinaryTree(BinaryTree* binaryTree)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		PrintBinaryTree(binaryTree->Root, 0);
		MenuBinaryTreeText();
		button = InputValidation(0, 5);

		switch (button)
		{
			case 0:
			{
				system("cls");
				DeleteBinaryTree(binaryTree);
				return 0;
			}
			case 1:
			{
				cout << "Введите элемент, который хотите добавить ";
				int newNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				BinaryTreeNode* newNode = CreateNewNode(newNodeValue);
				InsertNode(binaryTree, newNode);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "Введите элемент, который хотите удалить ";
				int key = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				bool isRemoved = RemoveNode(binaryTree, key);
				system("cls");
				
				if (isRemoved)
				{
					cout << "Элемент успешно удален\n";
				}
				else
				{
					cout << "Вы пытаетесь удалить несуществующий элемент\n";
				}
				break;
			}
			case 3:
			{
				cout << "Введите элемент, который хотите найти ";
				int findNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				BinaryTreeNode* findNode = FindInTree(binaryTree->Root, findNodeValue);
				system("cls");

				if (findNode != nullptr)
				{
					cout << "Элемент со значением " << findNode->Data
						<< " был найден\n";
				}
				else
				{
					cout << "Элемент не был найден\n";
				}
				break;
			}
			case 4:
			{
				system("cls");

				if (IsNotEmpty)
				{
					BinaryTreeNode* findNode = FindMax(binaryTree->Root);
					cout << "Элемент со значением " << findNode->Data
						<< " явлется максимальным\n";
				}
				else
				{
					cout << "В вашем дереве ничего нет\n";
				}
				break;
			}
			case 5:
			{
				system("cls");

				if (IsNotEmpty(binaryTree))
				{
					BinaryTreeNode* findNode = FindMin(binaryTree->Root);
					cout << "Элемент со значением " << findNode->Data
						<< " явлется минимальным\n";
				}
				else
				{
					cout << "В вашем дереве ничего нет\n";
				}
				break;
			}
		}
	}
}

void PrintBinaryTree(BinaryTreeNode* current, int level)
{
	if (current)
	{
		PrintBinaryTree(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << current->Data << endl;
		PrintBinaryTree(current->Left, level + 1);
	}
}

int MenuTreap(Treap* treap)
{
	Init(treap);
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		PrintTreap(treap->Root, 0);
		MenuTreapText();
		button = InputValidation(0, 5);

		switch (button)
		{
			case 0:
			{
				system("cls");
				DeleteTreap(treap);
				return 0;
			}
			case 1:
			{
				cout << "Введите элемент, который хотите добавить ";
				int newNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				InsertOptimize(newNodeValue, rand() % MAX_PRIORITY, treap->Root);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "Введите элемент, который хотите добавить ";
				int newNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				InsertNotOptimize(treap->Root, newNodeValue);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Введите элемент, который хотите удалить ";
				int key = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				bool isRemoved = RemoveOptimize(key, treap->Root);
				system("cls");

				if (isRemoved)
				{
					cout << "Элемент удален\n";
				}
				else
				{
					cout << "Вы пытаетесь удалить несуществующий элемент\n";
				}
				break;
			}
			case 4:
			{
				cout << "Введите элемент, который хотите удалить ";
				int key = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				bool isRemoved = RemoveNotOptimize(treap->Root, key);
				system("cls");

				if (isRemoved)
				{
					cout << "Элемент удален\n";
				}
				else
				{
					cout << "Вы пытаетесь удалить несуществующий элемент\n";
				}
				break;
			}
			case 5:
			{
				cout << "Введите элемент, который хотите найти ";
				int findNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				TreapNode* findNode = FindInTreap(treap->Root, findNodeValue);
				system("cls");

				if (findNode != nullptr)
				{
					cout << "Элемент со значением " << findNode->Data
						<< " был найден\n";
				}
				else
				{
					cout << "Элемент не был найден\n";
				}
				break;
			}
		}
	}
}

void PrintTreap(TreapNode* current, int level)
{
	if (current)
	{
		PrintTreap(current->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "       ";
		}
		cout << current->Data << ";" << current->Priority << endl;
		PrintTreap(current->Left, level + 1);
	}
}