#include "OutputInputFunc.h"

void PrintMainMenuText()
{
	cout << " _________________MENU________________\n";
	cout << " |To complet the work, press 0.       |\n";
	cout << " |To work with the hashtable, press 1.|\n";
	cout << " |To work with dictionary, press 2.   |\n";
	cout << " |____________________________________|\n";
	cout << endl;
}

void PrintMenuHashTableText()
{
	cout << " ______________________MENU____________________\n";
	cout << " |To complet the work, press 0.                |\n";
	cout << " |To insert a node in the hashtable, press 1.  |\n";
	cout << " |To remove a node from the hashtable, press 2.|\n";
	cout << " |To find a node in the hashtable, press 1.    |\n";
	cout << " |_____________________________________________|\n";
	cout << endl;
}

void PrintMenuDictionaryText()
{
	cout << " ______________________MENU____________________\n";
	cout << " |To complet the work, press 0.             |\n";
	cout << " |To written in the dictionary, press 1.  |\n";
	cout << " |To remove from the dictionary, press 2.|\n";
	cout << " |To find in the hashtable, press 1.    |\n";
	cout << " |_____________________________________________|\n";
	cout << endl;
}

int StartMenuHashTable(HashTable* hashTable)
{
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		int coefFullnes = (hashTable->Size * 4) / 3;

		if (hashTable->NumberOfFilledNodes == coefFullnes)
		{
			hashTable = Rehashing(hashTable);
		}
		ShowTable(hashTable);
		PrintMenuHashTableText();
		int button = InputValidation(0, 3);

		switch (button)
		{
			case 0:
			{
				DeleteTable(hashTable);
				system("cls");
				return 0;
			}
			case 1:
			{
				cout << "Enter the Key ";
				string key = InputKeyOrValue();
				cout << "Enter the Value ";
				string value = InputKeyOrValue();
				Node* newNode = CreateNewNode(key, value);
				int newNodeIndex = HashFunction(key, hashTable->Size);
				system("cls");
				bool isInserted = InsertNode(hashTable, newNode, newNodeIndex);

				if (isInserted == false)
				{
					PrintErrorRepeat();
				}
				break;
			}
			case 2:
			{
				cout << "Enter the delete key ";
				string key = InputKeyOrValue();
				system("cls");
				bool isRemoved = RemoveNode(hashTable, key);

				if (isRemoved == false)
				{
					PrintErrorRemove();
				}
				break;
			}
			case 3:
			{
				cout << "Enter the search key ";
				string key = InputKeyOrValue();
				system("cls");
				Node* foundNode = FindNode(hashTable, key);

				if (foundNode)
				{
					cout << "Information was found on your request: "
						<< foundNode->Value << endl;
				}
				else
				{
					cout << "Information was not found on your request." << endl;
				}
				break;
			}
		}
	}
}

int StartMenuDictionary(Dictionary* dictionary)
{
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		int coefFullnes = (dictionary->Table->Size * 4) / 3;

		if (dictionary->Table->NumberOfFilledNodes == coefFullnes)
		{
			dictionary->Table = Rehashing(dictionary->Table);
		}
		ShowDictonary(dictionary);
		ShowTable(dictionary->Table);
		PrintMenuDictionaryText();
		int button = InputValidation(0, 3);

		switch (button)
		{
			case 0:
			{
				DeleteDictionary(dictionary);
				system("cls");
				return 0;
			}
			case 1:
			{
				cout << "Enter the Key ";
				string key = InputKeyOrValue();
				cout << "Enter the Value ";
				string value = InputKeyOrValue();
				Node* newNode = CreateNewNode(key, value);
				system("cls");
				bool isInserted = InsertByKey(dictionary, newNode, key);

				if (isInserted == false)
				{
					PrintErrorInsert();
				}
				break;
			}
			case 2:
			{
				cout << "Enter the delete key ";
				string key = InputKeyOrValue();
				system("cls");
				bool isRemoved = RemoveByKey(dictionary, key);

				if (isRemoved == false)
				{
					PrintErrorRemove();
				}
				break;
			}
			case 3:
			{
				cout << "Enter the search key ";
				string key = InputKeyOrValue();
				system("cls");
				Node* foundNode = FindValue(dictionary, key);

				if (foundNode)
				{
					cout << "Information was found on your request: "
						<< foundNode->Value << endl;
				}
				else
				{
					cout << "Information was not found on your request." << endl;
				}
				break;
			}
		}
	}
}

void ShowTable(HashTable* hashTable)
{
	Node* current;
	cout << "_________HASHTABLE________\n";

	for (int i = 0; i < hashTable->Size; i++)
	{
		current = hashTable->Array[i]->Head;

		if (current != nullptr)
		{
			PrintNode(current, i);
			current = current->Next;

			while (current != nullptr)
			{
				cout << " >> ";
				PrintNode(current, i);
				current = current->Next;
			}
		}
		else
		{
			cout << "[" << i << "] Key: < > Value: < >\n";
		}
	}
}

void ShowDictonary(Dictionary* dictonary)
{
	cout << "_______Dictonary________\n";
	Node* current;
	int j = 0;

	for (int i = 0; i < dictonary->Table->Size; i++)
	{
		current = dictonary->Table->Array[i]->Head;

		if (current != nullptr)
		{
			PrintNode(current, j);
			current = current->Next;
			j++;

			while (current != nullptr)
			{
				PrintNode(current, j);
				current = current->Next;
				j++;
			}
		}
	}
}

void PrintNode(Node* node, int index)
{
	cout << "[" << index << "] Key: " << node->Key
		<< " Value: " << node->Value << endl;
}

void PrintErrorInsert()
{
	cout << "Error! You are trying to insert an element with existing key\n";
}

void PrintErrorRemove()
{
	cout <<"Error! You are trying to remove an item that doesn't exist\n";
}

void PrintErrorRepeat()
{
	cout << "Error! You are trying to insert an item that does exist\n";
}

string InputKeyOrValue()
{
	string inputValue;
	getline(cin, inputValue);
	return inputValue;
}