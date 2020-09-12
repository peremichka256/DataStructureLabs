#include "OutputFunctions.h"

void MenuText()
{
	cout << " ____________________________MENU___________________________ \n";
	cout << " |To complete work, press 0                                 |\n";
	cout << " |To work with the stack, press 1.                          |\n";
	cout << " |To work with the ring buffer, press 2.                    |\n";
	cout << " |To work with the queue based on the ring buffer, press 3. |\n";
	cout << " |To work with the queue on two stacks, press 4.            |\n";
	cout << " |__________________________________________________________|\n";
}

void PrintMenuStackText()
{
	cout << " ____________________MENU______________\n";
	cout << " |To complete the stack work, press 0. |\n";
	cout << " |To push in stack, press 1.           |\n";
	cout << " |To pop from stack, press 2.          |\n";
	cout << " |To add a new cell, press 3.          |\n";
	cout << " |_____________________________________|\n";
}			  

void PrintMenuBufferText()
{
	cout << " ____________________MENU______________\n";
	cout << " To complete the buffer work, press 0. |\n";
	cout << " |To push in buffer, press 1.          |\n";
	cout << " |To pop from buffer, press 2.         |\n";
	cout << " |To add a new cell, press 3.          |\n";
	cout << " |_____________________________________|\n";
}

void PrintMenuQueueText()
{
	cout << " ____________________MENU______________\n";
	cout << " |To complete the queue work, press 0. |\n";
	cout << " |To push in queue, press 1.           |\n";
	cout << " |To pop from queue, press 2.          |\n";
	cout << " |_____________________________________|\n";
}

int PrintMenuStack(Stack* stack)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowStack(stack);
		PrintMenuStackText();
		cout << endl;
		button = InputValidation(0, 3);

		switch (button)
		{
			case buttonForEnd:
			{
				DeleteStack(stack);
				system("cls");
				return 0;
			}
			case 1:
			{
				cout << "Enter the item value that you want to push to the stack. "
					<< "Range of values: [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				Push(stack, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(stack->Size))
				{
					system("cls");
					cout << "Pop from the stack: " << Pop(stack) << endl;
				}
				break;
			}
			case 3:
			{
				AddCell(stack);
				system("cls");
				break;

			}
		}
	}
}

int PrintMenuBuffer(RingBuffer* ring)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		cout << "Are free " << GetFreeMemoryInfo(ring) << " cell" << endl;
		cout << "Are employed " << GetEmployedMemoryInfo(ring) << " cell" << endl;
		ShowBuffer(ring);
		PrintMenuBufferText();
		cout << endl;
		button = InputValidation(0, 3);

		switch (button)
		{
			case buttonForEnd:
			{
				DeleteBuffer(ring);
				system("cls");
				return 0;
			}
			case 1:
			{
				cout << "Enter the item value that you want to push to the buffer. "
					<< "Range of values: [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				PushInBuffer(ring, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Pop from the buffer: " << PopFromBuffer(ring) << endl;
				cout << endl;
				ring->IndexOutput = ring->IndexOutput->Next;
				break;
			}
			case 3:
			{
				AddNewNode(ring);
				system("cls");
				break;
			}
		}
	}
}

int PrintMenuQueueBuffer(QueueRingBuffer* queue)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowQueueBuffer(queue);
		PrintMenuQueueText();
		cout << endl;
		button = InputValidation(0, 2);

		switch (button)
		{
			case buttonForEnd:
			{
				DeleteQueueBuffer(queue, queue->RingBuffer->Size);
				system("cls");
				return 0;
			}
			case 1:
			{
				cout << "Enter the item value that you want to enqueue to the queue. "
					<< "Range of values: [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				EnqueueBuffer(queue, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(queue->RingBuffer->Size))
				{
					cout << endl;
					int deleteItem = 0;
					cout << "Dequeue: " << DequeueBuffer(queue, deleteItem)
						<< endl;
				}
				break;
			}
		}
	}
}

int PrintMenuQueueStack(QueueStack* queue)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowQueueStack(queue);
		PrintMenuQueueText();
		cout << endl;
		button = InputValidation(0, 2);

		switch (button)
		{
		case buttonForEnd:
			{
				DeleteQueueStack(queue, queue->Input->Size);
				system("cls");
				return 0;
			}
			case 1:
			{
				cout << "Enter the item value that you want to enqueue to the queue. "
					<< "Range of values: [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				EnqueueStack(queue, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(queue->Output->Size))
				{
					system("cls");
					cout << "Dequeue: " << DequeueStack(queue)
						<< "\n";
				}
				break;
			}
		}
	}
}

void ShowStack(Stack* stack)
{
	if (IsNotEmpty(stack->Size))
	{
		int temp = stack->Top;
		temp++;

		if (temp == stack->Size)
		{
			cout << "Your stack overflow, to place a new element, expand the buffer\n";
		}

		for (int i = stack->Top; i >= 0; i--)
		{
			cout << "[" << i << "] " << stack->Array[i] << endl;
		}
	}
	else
	{
		cout << "Ur stack is empty\n";
	}
}

void ShowBuffer(RingBuffer* ring)
{
	BufferNode* current = ring->Begin;

	for (int i = 0; i < ring->Size; i++)
	{
		if (current->IsHaveInfo)
		{
			cout << " " << current->Data << " ";
		}
		else
		{
			cout << " _ ";
		}
		current = current->Next;
	}
	cout << endl;
}

void ShowQueueBuffer(QueueRingBuffer* queue)
{
	if (queue->RingBuffer->Size)
	{
		BufferNode* current = queue->RingBuffer->IndexOutput;

		for (int i = 0; i < queue->RingBuffer->Size; i++)
		{
			cout << "[" << i << "] " << current->Data << endl;
			current = current->Next;
		}
		cout << endl;
	}
	else
	{
		cout << "Ur queue is empty " << endl;
	}
}

void ShowQueueStack(QueueStack* queue)
{
	if (IsNotEmpty(queue->Input->Size))
	{
		for (int i = queue->Input->Top; i >= 0; i--)
		{
			cout << "[" << i << "] " << queue->Input->Array[i] <<"\t"<< queue->Output->Array[i] << endl;
		}
	}
	else
	{
		cout << "Ur stacks are ampty\n";
	}
}