#pragma once
#include<iostream>
#include<string>
using namespace std;

struct DynamicArray
{
	int Length;
	int Capacity;
	int* Array;			
};


DynamicArray* CreateDynamicArray();
void DeleteDynamicArray(DynamicArray* dynamicArray);
void DefineFieldArray(DynamicArray* dynamicArray);
void RecreatingMemory(DynamicArray* dynamicArray);
void CopyArray(int* array1, int* array2, int length);
void DeleteItem(DynamicArray* dynamicArray, int indexToDelete);
void InsertByIndex(DynamicArray* dynamicArray, int item, int itemValue);
void Sort(DynamicArray* dynamicArray);
void LineSearch(DynamicArray* dynamicArray, int key);
void BinarSearch(DynamicArray* dynamicArray, int key);

const double GROWTH_FACTOR = 1.5;
const int MIN_ELEMENT = -100;
const int MAX_ELEMENT = 100;
const int MIN_LENGTH = 0;
const int MAX_LENGTH = 100;

//make something