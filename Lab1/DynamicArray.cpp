#include "DynamicArray.h"
#include "OutputFunc.h"


DynamicArray* CreateDynamicArray()
{
	DynamicArray* ourDynamicArray = new DynamicArray;
	ourDynamicArray->Capacity = InputValidation(MIN_LENGTH, MAX_LENGTH);
	ourDynamicArray->Array = new int[ourDynamicArray->Capacity];
	ourDynamicArray->Length = 0;

	for (int i = 0; i < ourDynamicArray->Capacity; i++)
	{
		ourDynamicArray->Array[i] = rand() % MAX_ELEMENT * 2 - MAX_ELEMENT;
		ourDynamicArray->Length++;
	}
	return ourDynamicArray;
}

void DeleteDynamicArray(DynamicArray* dynamicArray)
{
	delete[] dynamicArray->Array;
	delete dynamicArray;
}

void RecreatingMemory(DynamicArray* dynamicArray)
{
	if (dynamicArray->Length == dynamicArray->Capacity)
	{
		dynamicArray->Capacity = GROWTH_FACTOR * dynamicArray->Length;
		int* newArray = new int[dynamicArray->Capacity];
		CopyArray(newArray, dynamicArray->Array, dynamicArray->Length);
		delete[] dynamicArray->Array;
		dynamicArray->Array = newArray;
	}
}

void DefineFieldArray(DynamicArray* dynamicArray)
{
	cout << "\nѕолный доступный объем массива = " << dynamicArray->Capacity
		<< " элементов";
	cout << "\nј на данный момент в массиве " << dynamicArray->Length
		<< " элементов\n";
}

void DeleteItem(DynamicArray* dynamicArray, int indexToDelete)
{
	for (int i = indexToDelete; i < dynamicArray->Length; ++i)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i + 1];
	}
	dynamicArray->Length--;
}

void InsertByIndex(DynamicArray* dynamicArray, int newItemIndex, int itemValue)
{
	for (int i = dynamicArray->Length; i > newItemIndex; i--)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i - 1];
	}
	dynamicArray->Array[newItemIndex] = itemValue;
	dynamicArray->Length++;
}

void Sort(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length - 1; i++)
	{
		for (int j = 0; j < dynamicArray->Length - i - 1; j++)
		{
			if (dynamicArray->Array[j] > dynamicArray->Array[j + 1])
			{
				int temp = dynamicArray->Array[j];
				dynamicArray->Array[j] = dynamicArray->Array[j + 1];
				dynamicArray->Array[j + 1] = temp;
			}
		}
	}
}

void LineSearch(DynamicArray* dynamicArray,int key)
{
	int counter = 0;

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == key)
		{
			cout << "Ёлемент " << i << " равен искомому числу\n";
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "»скомое число не было найдено в массиве\n";
	}
}

void BinarSearch(DynamicArray* dynamicArray, int key)
{
	Sort(dynamicArray);
	int checking = dynamicArray->Length;

	if ((checking == 1))
	{
		cout << "\nЁлемент массива номер 0 равен искомому элементу\n";
	}

	else
	{ 
		int checkCounter = 0;

		while (checking != 1)
		{
			checking /= 2;
			checkCounter++;
		}

		int checkCounterWhile = 0;
		int counter = 0;
		int first = 0;
		int last = dynamicArray->Length;
		int mid = 0;

		while ((counter != 1) && !(checkCounterWhile == checkCounter))
		{
			mid = (first + last) / 2;

			if (dynamicArray->Array[mid] == key)
			{
				counter++;
				cout << "\nЁлемент массива номер " << mid
					<< " равен искомому элементу\n";
			}
			else if (dynamicArray->Array[mid] > key)
			{
				last = mid - 1;
				checkCounterWhile++;
			}
			else if (dynamicArray->Array[mid] < key)
			{
				first = mid + 1;
				checkCounterWhile++;
			}
		}
	}
}

void CopyArray(int* array1, int* array2, int length)
{
	for (int i = 0; i < length; ++i)
	{
		array1[i] = array2[i];
	}
}

