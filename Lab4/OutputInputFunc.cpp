#include "OutputInputFunc.h"

void MainMenuText()
{
	cout << " _________________MENU_______________\n";
	cout << " |Для завершени работы нажмите 0.    |\n";
	cout << " |Для работы с таблицей нажмите 1.   |\n";
	cout << " |Для со словарем нажмите 2.         |\n";
	cout << " |___________________________________|\n";
	cout << endl;
}

void MenuHashTableText()
{
	cout << " ______________________MENU____________________\n";
	cout << " |Для завершени работы нажмите 0.              |\n";
	cout << " |Для добавления записи в таблицу нажмите 1.   |\n";
	cout << " |Для удаления записи из таблицы нажмите 2.    |\n";
	cout << " |Для поиска записи в таблице нажмите 3.       |\n";
	cout << " |_____________________________________________|\n";
	cout << endl;
}

void MenuDictionaryText()
{
	cout << " ______________________MENU____________________\n";
	cout << " |Для завершени работы нажмите 0.              |\n";
	cout << " |Для добавления записи в словарь нажмите 1.   |\n";
	cout << " |Для удаления записи из словаря нажмите 2.    |\n";
	cout << " |Для поиска записи в словаре нажмите 3.       |\n";
	cout << " |_____________________________________________|\n";
	cout << endl;
}

int MenuHashTable(HashTable* hashTable)
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
		MenuHashTableText();
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
				cout << "Введите Key ";
				string key = InputKeyOrValue();
				cout << "Введите Value ";
				string value = InputKeyOrValue();
				Node* newNode = CreateNewNode(key, value);
				int newNodeIndex = HashFunction(key, hashTable->Size);
				system("cls");
				bool isInserted = InsertNode(hashTable, newNode, newNodeIndex);

				if (isInserted == false)
				{
					ErrorMessegeRepeat();
				}
				break;
			}
			case 2:
			{
				cout << "Введите Key записи, которую хотите удалить ";
				string key = InputKeyOrValue();
				system("cls");
				bool isRemoved = RemoveNode(hashTable, key);

				if (isRemoved == false)
				{
					ErrorMessegeRemove();
				}
				break;
			}
			case 3:
			{
				cout << "Введите Key записи, которую хотите найти ";
				string key = InputKeyOrValue();
				system("cls");
				Node* foundNode = FindNode(hashTable, key);

				if (foundNode)
				{
					cout << "По вашему запросу была найдена информация "
						<< foundNode->Value << endl;
				}
				else
				{
					cout << "Запись не найдена" << endl;
				}
				break;
			}
		}
	}
}

int MenuDictionary(Dictionary* dictionary)
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
		MenuDictionaryText();
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
				cout << "Введите Key ";
				string key = InputKeyOrValue();
				cout << "Введите Value ";
				string value = InputKeyOrValue();
				Node* newNode = CreateNewNode(key, value);
				system("cls");
				bool isInserted = InsertByKey(dictionary, newNode, key);

				if (isInserted == false)
				{
					ErrorMessegeInsert();
				}
				break;
			}
			case 2:
			{
				cout << "Введите Key записи, которую хотите удалить ";
				string key = InputKeyOrValue();
				system("cls");
				bool isRemoved = RemoveByKey(dictionary, key);

				if (isRemoved == false)
				{
					ErrorMessegeRemove();
				}
				break;
			}
			case 3:
			{
				cout << "Введите Key записи, которую хотите найти ";
				string key = InputKeyOrValue();
				system("cls");
				Node* foundNode = FindValue(dictionary, key);

				if (foundNode)
				{
					cout << "По вашему запросу была найдена информация "
						<< foundNode->Value << endl;
				}
				else
				{
					cout << "Запись не найдена" << endl;
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

void ErrorMessegeInsert()
{
	cout << "Ошибка! Вы пытаетесь вставить элемент с уже существующим key\n";
}

void ErrorMessegeRemove()
{
	cout <<"Ошибка! Вы пытаетесь удалить несуществующий элемент\n";
}

void ErrorMessegeRepeat()
{
	cout << "Ошибка! Вы пытаетесь вставить уже существующий элемент\n";
}

string InputKeyOrValue()
{
	string inputValue;
	getline(cin, inputValue);
	return inputValue;
}