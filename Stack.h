#pragma once
#include "CommonFunc.h"

struct Stack
{
	int Size;
	int Top;
	int* Array;
};

Stack* CreateStack(int size);
Stack* InitStack(int size);
void Push(Stack* stack, int data);
int Pop(Stack* stack);
void DeleteStack(Stack* stack);
void AddCell(Stack* stack);
void CopyArray(int* array1, int* array2, int length);