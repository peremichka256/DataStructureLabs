#include "OutputFunctions.h"

void MenuText()
{
	cout << " ____________________________MENU____________________________ \n";
	cout << " |Для завершени работы нажмите 0.                            |\n";
	cout << " |Для работы со стеком нажмите 1.                            |\n";
	cout << " |Для работы с кольцевым буфером 2.                          |\n";
	cout << " |Для работы с очередью на базе кольцевого буфера нажмите 3. |\n";
	cout << " |Для работы с очередью на базе двух стеков нажмите 4.       |\n";
	cout << " |___________________________________________________________|\n";
}

void MenuStackText()
{
	cout << " ____________________MENU_____________________ \n";
	cout << " |Для завершени работы со стеком нажмите 0.   |\n";
	cout << " |Для помещения элемента в стек нажмите 1.    |\n";
	cout << " |Для извлечения элемента из стека нажмите 2. |\n";
	cout << " |Для добавления новой ячейки нажмите 3.      |\n";
	cout << " |____________________________________________|\n";
}			  

void MenuBufferText()
{
	cout << " ____________________MENU_______________________\n";
	cout << " |Для завершени работы со стеком нажмите 0.     |\n";
	cout << " |Для помещения элемента в буфер нажмите 1.     |\n";
	cout << " |Для извлечения элемента из буфера нажмите 2   |\n";
	cout << " |Для добавления новой ячейки в буфер нажмите 3.|\n";
	cout << " |______________________________________________|\n";
}

void MenuQueueText()
{
	cout << " ____________________MENU______________________\n";
	cout << " |Для завершени работы с очередью нажмите 0.   |\n";
	cout << " |Для помещения элемента в очередь нажмите 1.  |\n";
	cout << " |Для извлечения элемента из очереди нажмите 2.|\n";
	cout << " |_____________________________________________|\n";
}

int MenuStack(Stack* stack)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowStack(stack);
		MenuStackText();
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
				cout << "Введите значие элемента, который добавится в стек. "
					<< "В диапазоне [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				Push(stack, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(stack->Size))
				{
					system("cls");
					cout << "Достали из стека элемент " << Pop(stack) << endl;
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

int MenuBuffer(RingBuffer* ring)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		cout << "Cвободно " << FreeMemoryInfo(ring) << " ячеек" << endl;
		cout << "Занято " << EmployedMemoryMemoryInfo(ring) << " ячеек" << endl;
		ShowBuffer(ring);
		MenuBufferText();
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
				cout << "Введите значие элемента, который добавится в буфер. "
					<< "В диапазоне [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				PushInBuffer(ring, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Достали из буфера элемент " << PopFromBuffer(ring) << endl;
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

int MenuQueueBuffer(QueueRingBuffer* queue)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowQueueBuffer(queue);
		MenuQueueText();
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
				cout << "Введите значие элемента, который добавится в буфер. "
					<< "В диапазоне [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
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
					cout << "Достали из очереди элемент " << DequeueBuffer(queue, deleteItem)
						<< endl;
				}
				break;
			}
		}
	}
}

int MenuQueueStack(QueueStack* queue)
{
	int button;
	bool isExitFromWhile = true;

	while (isExitFromWhile)
	{
		ShowQueueStack(queue);
		MenuQueueText();
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
				cout << "Введите значие элемента, который добавится в очередь. "
					<< "В диапазоне [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				EnqueueStack(queue, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(queue->Output->Size))
				{
					system("cls");
					cout << "Достали из очереди элемент " << DequeueStack(queue)
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
			cout << "Ваш стек полон, для помещения нового элемента расширьте буфер\n";
		}

		for (int i = stack->Top; i >= 0; i--)
		{
			cout << "[" << i << "] " << stack->Array[i] << endl;
		}
	}
	else
	{
		cout << "Ваш стек пуст\n";
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
		cout << "В вашей очереди нет элементов " << endl;
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
		cout << "Ваши стеки пусты\n";
	}
}