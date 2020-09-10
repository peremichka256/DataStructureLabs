#include "DynamicArray.h"
#include "OutputFunc.h"


DynamicArray* CreateDynamicArray()
{
	DynamicArray* dynamicArray = new DynamicArray;
	dynamicArray->Capacity = InputValidation(MIN_LENGTH, MAX_LENGTH);
	dynamicArray->Array = new int[dynamicArray->Capacity];
	dynamicArray->Length = 0;

	for (int i = 0; i < dynamicArray->Capacity; i++)
	{
		dynamicArray->Array[i] = rand() % MAX_ELEMENT * 2 - MAX_ELEMENT;
		dynamicArray->Length++;
	}
	return dynamicArray;
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

//TODO: move all the output to OutputFunc(?!)
void DefineFieldArray(DynamicArray* dynamicArray)
{
	cout << "\nCapacity of array = " << dynamicArray->Capacity
		<< " items";
	cout << "\nCurrently in the array " << dynamicArray->Length
		<< " items\n";
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

//TODO: move all the output to OutputFunc(?!)
void LineSearch(DynamicArray* dynamicArray,int key)
{
	int counter = 0;

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == key)
		{
			cout << "Item " << i << "is equal to the value\n";
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "The desired value was not found in the array\n";
	}
}

//TODO: move all the output to OutputFunc(?!)
void BinarySearch(DynamicArray* dynamicArray, int key)
{
	Sort(dynamicArray);
	int checking = dynamicArray->Length;

	if ((checking == 1))
	{
		cout << "\nArray item number 0 equals the desired element\n";
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
				cout << "\nItem " << mid
					<< " is equal to the value\n";
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

