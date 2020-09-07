#include "QueueRingBuffer.h"
#include "QueueStack.h"
#include "RingBuffer.h"
#include "Stack.h"
#include "OutputFunctions.h"

int main() 
{
	setlocale(LC_ALL, "Rus");
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		MenuText();
		cout << endl;
		button = InputValidation(0, 4);

		switch (button)
		{
			case buttonForEnd:
			{
				cout << "\nРабота окончена\n";
				return 0;
			}
			case 1:
			{
				cout << "Введите сколько элеменетов будет в стеке (не больше " 
					<< MAX_SIZE << " и не меньше " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				MenuStack(InitStack(size));
				break;
			}
			case 2:
			{
				cout << "Введите сколько элеменетов будет в вашем буфере (не больше " 
					<< MAX_SIZE << " и не меньше " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				MenuBuffer(InitBuffer(size));
				break;
			}
			case 3:
			{
				cout << "Введите сколько элеменетов будет в вашей очереди (не больше " 
					<< MAX_SIZE << " и не меньше " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				MenuQueueBuffer(CreateQueueBuffer(size));
				break;
			}
			case 4:
			{
				cout << "Введите сколько элеменетов будет в вашей очереди (не больше " 
					<< MAX_SIZE << " и не меньше " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				MenuQueueStack(CreateQueueStack(size));
				break;
			}
		}
	}
}