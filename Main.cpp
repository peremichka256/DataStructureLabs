#include "QueueRingBuffer.h"
#include "QueueStack.h"
#include "RingBuffer.h"
#include "Stack.h"
#include "OutputFunctions.h"

int main() 
{
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
				cout << "\nWork is completing.\n";
				return 0;
			}
			case 1:
			{
				cout << "Enter how many elemens will be in the stack "
					<< "(not more than " << MAX_SIZE
					<< " and not less than " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				PrintMenuStack(InitStack(size));
				break;
			}
			case 2:
			{
				cout << "Enter how many elemens will be in the buffer "
					<< "(not more than " << MAX_SIZE
					<< " and not less than " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				PrintMenuBuffer(InitBuffer(size));
				break;
			}
			case 3:
			{
				cout << "Enter how many elemens will be in the queue buffer "
					<< "(not more than " << MAX_SIZE
					<< " and not less than " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				PrintMenuQueueBuffer(CreateQueueBuffer(size));
				break;
			}
			case 4:
			{
				cout << "Enter how many elemens will be in the queue stack "
					<< "(not more than " << MAX_SIZE
					<< " and not less than " << MIN_SIZE << ") ";
				int size = InputValidation(MIN_SIZE, MAX_SIZE);
				system("cls");
				PrintMenuQueueStack(CreateQueueStack(size));
				break;
			}
		}
	}
}