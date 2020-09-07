#include "OutputFunc.h"
#include "CommonFunc.h"

void MenuText()
{
	cout << "_______________________MENU_______________________\n";
	cout << "|��� ���������� ������ ������� 0.                |\n";
	cout << "|��� ������ � �������� ������� ������ ������� 1. |\n";
	cout << "|��� ������ � ���������� ������� ������� 2.      |\n";
	cout << "|________________________________________________|\n";
}

void MenuBinaryTreeText()
{
	cout << "__________________________MENU_________________________\n";
	cout << "|��� ���������� ������ � ������� ������� 0.           |\n";
	cout << "|��� ���������� �������� � �������� ������ ������� 1. |\n";
	cout << "|��� �������� �������� �� ��������� ������ ������� 2. |\n";
	cout << "|��� ������ �������� � �������� ������ ������� 3.     |\n";
	cout << "|��� ������ ��������� � �������� ������ ������� 4.    |\n";
	cout << "|��� ������ �������� � �������� ������ ������� 5.     |\n";
	cout << "|_____________________________________________________|\n";
	cout << endl;
}

void MenuTreapText()
{
	cout << "____________________________MENU___________________________\n";
	cout << "|��� ���������� ������ � ������� ������� 0.               |\n";
	cout << "|��� ����������������� ���������� �������� � ������� 1.   |\n";
	cout << "|��� ������������������� ���������� �������� � ������� 2. |\n";
	cout << "|��� ����������������� �������� �������� ������� 3.       |\n";
	cout << "|��� ������������������� �������� �������� ������� 4.     |\n";
	cout << "|��� ������ �������� ������� 5.                           |\n";
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
				cout << "������� �������, ������� ������ �������� ";
				int newNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				BinaryTreeNode* newNode = CreateNewNode(newNodeValue);
				InsertNode(binaryTree, newNode);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "������� �������, ������� ������ ������� ";
				int key = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				bool isRemoved = RemoveNode(binaryTree, key);
				system("cls");
				
				if (isRemoved)
				{
					cout << "������� ������� ������\n";
				}
				else
				{
					cout << "�� ��������� ������� �������������� �������\n";
				}
				break;
			}
			case 3:
			{
				cout << "������� �������, ������� ������ ����� ";
				int findNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				BinaryTreeNode* findNode = FindInTree(binaryTree->Root, findNodeValue);
				system("cls");

				if (findNode != nullptr)
				{
					cout << "������� �� ��������� " << findNode->Data
						<< " ��� ������\n";
				}
				else
				{
					cout << "������� �� ��� ������\n";
				}
				break;
			}
			case 4:
			{
				system("cls");

				if (IsNotEmpty)
				{
					BinaryTreeNode* findNode = FindMax(binaryTree->Root);
					cout << "������� �� ��������� " << findNode->Data
						<< " ������� ������������\n";
				}
				else
				{
					cout << "� ����� ������ ������ ���\n";
				}
				break;
			}
			case 5:
			{
				system("cls");

				if (IsNotEmpty(binaryTree))
				{
					BinaryTreeNode* findNode = FindMin(binaryTree->Root);
					cout << "������� �� ��������� " << findNode->Data
						<< " ������� �����������\n";
				}
				else
				{
					cout << "� ����� ������ ������ ���\n";
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
				cout << "������� �������, ������� ������ �������� ";
				int newNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				InsertOptimize(newNodeValue, rand() % MAX_PRIORITY, treap->Root);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "������� �������, ������� ������ �������� ";
				int newNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				InsertNotOptimize(treap->Root, newNodeValue);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "������� �������, ������� ������ ������� ";
				int key = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				bool isRemoved = RemoveOptimize(key, treap->Root);
				system("cls");

				if (isRemoved)
				{
					cout << "������� ������\n";
				}
				else
				{
					cout << "�� ��������� ������� �������������� �������\n";
				}
				break;
			}
			case 4:
			{
				cout << "������� �������, ������� ������ ������� ";
				int key = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				bool isRemoved = RemoveNotOptimize(treap->Root, key);
				system("cls");

				if (isRemoved)
				{
					cout << "������� ������\n";
				}
				else
				{
					cout << "�� ��������� ������� �������������� �������\n";
				}
				break;
			}
			case 5:
			{
				cout << "������� �������, ������� ������ ����� ";
				int findNodeValue = InputValidation(MIN_ITEM_VALUE, MAX_ITEM_VALUE);
				TreapNode* findNode = FindInTreap(treap->Root, findNodeValue);
				system("cls");

				if (findNode != nullptr)
				{
					cout << "������� �� ��������� " << findNode->Data
						<< " ��� ������\n";
				}
				else
				{
					cout << "������� �� ��� ������\n";
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