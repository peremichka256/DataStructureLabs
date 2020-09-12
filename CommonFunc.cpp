#include"CommonFunc.h"

bool IsNotEmpty(int size)
{
	return size;
}

bool CheckingForInteger(string value)
{
	int size = value.length();

	if (isdigit(value[0]) || value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit(value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int InputValidation(int min, int max)
{
	string inputValue;

	while (true)
	{
		getline(cin, inputValue);

		if (inputValue.length() <= MAX_INTEGER)
		{
			int outputValue;

			if (CheckingForInteger(inputValue) == false
				|| stoll(inputValue) < min
				|| stoll(inputValue) > max)
			{
				cout << endl << "Error! Try again: ";
				inputValue.clear();
			}
			else
			{
				outputValue = stoll(inputValue);
				return outputValue;
			}
		}
		else
		{
			cout << endl << "Error! Try again: ";
			inputValue.clear();
		}
	}
}