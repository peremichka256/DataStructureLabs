#include "Stack.h"

Stack* CreateStack(int size)
{
	Stack* stack = new Stack;
	stack->Size = size;
	stack->Array = new int[size];
	stack->Top = --size;
	return stack;
}

Stack* InitStack(int size)
{
	srand(time(nullptr));
	Stack* stack = CreateStack(size);

	for (int i = 0; i < size; i++)
	{
		stack->Array[i] = rand() % 100;
	}
	return stack;
}

void Push(Stack* stack, int data)
{
	int temp = stack->Size;
	temp--;

	if (temp != stack->Top)
	{
		stack->Top++;
		stack->Array[stack->Top] = data;
	}
}

int Pop(Stack* stack)
{
	if (IsNotEmpty)
	{
		int popItem = stack->Array[stack->Top];
		stack->Top--;
		return popItem;
	}
}

void DeleteStack(Stack* stack)
{
	delete[] stack->Array;
	delete stack;
}

void AddCell(Stack* stack)
{
	stack->Size++;
	int* newArray = new int[stack->Size];
	CopyArray(newArray, stack->Array, stack->Top);
	delete[] stack->Array;
	stack->Array = newArray;
}

void CopyArray(int* array1, int* array2, int length)
{
	for (int i = 0; i <= length; i++)
	{
		array1[i] = array2[i];
	}
}
