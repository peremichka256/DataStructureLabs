#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool IsNotEmpty(int size);
bool CheckingForInteger(string value);
int InputValidation(int min, int max);

int const MIN_SIZE = 0;
int const MAX_SIZE = 513;
int const MIN_VALUE = 0;
int const MAX_VALUE = 50;
int const MAX_INTEGER = 11;
int const buttonForEnd = 0;