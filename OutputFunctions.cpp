#include "OutputFunctions.h"

void MenuText()
{
	cout << " ____________________________MENU____________________________ \n";
	cout << " |��� ��������� ������ ������� 0.                            |\n";
	cout << " |��� ������ �� ������ ������� 1.                            |\n";
	cout << " |��� ������ � ��������� ������� 2.                          |\n";
	cout << " |��� ������ � �������� �� ���� ���������� ������ ������� 3. |\n";
	cout << " |��� ������ � �������� �� ���� ���� ������ ������� 4.       |\n";
	cout << " |___________________________________________________________|\n";
}

void MenuStackText()
{
	cout << " ____________________MENU_____________________ \n";
	cout << " |��� ��������� ������ �� ������ ������� 0.   |\n";
	cout << " |��� ��������� �������� � ���� ������� 1.    |\n";
	cout << " |��� ���������� �������� �� ����� ������� 2. |\n";
	cout << " |��� ���������� ����� ������ ������� 3.      |\n";
	cout << " |____________________________________________|\n";
}			  

void MenuBufferText()
{
	cout << " ____________________MENU_______________________\n";
	cout << " |��� ��������� ������ �� ������ ������� 0.     |\n";
	cout << " |��� ��������� �������� � ����� ������� 1.     |\n";
	cout << " |��� ���������� �������� �� ������ ������� 2   |\n";
	cout << " |��� ���������� ����� ������ � ����� ������� 3.|\n";
	cout << " |______________________________________________|\n";
}

void MenuQueueText()
{
	cout << " ____________________MENU______________________\n";
	cout << " |��� ��������� ������ � �������� ������� 0.   |\n";
	cout << " |��� ��������� �������� � ������� ������� 1.  |\n";
	cout << " |��� ���������� �������� �� ������� ������� 2.|\n";
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
				cout << "������� ������ ��������, ������� ��������� � ����. "
					<< "� ��������� [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				Push(stack, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(stack->Size))
				{
					system("cls");
					cout << "������� �� ����� ������� " << Pop(stack) << endl;
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
		cout << "C������� " << FreeMemoryInfo(ring) << " �����" << endl;
		cout << "������ " << EmployedMemoryMemoryInfo(ring) << " �����" << endl;
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
				cout << "������� ������ ��������, ������� ��������� � �����. "
					<< "� ��������� [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				PushInBuffer(ring, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				cout << "������� �� ������ ������� " << PopFromBuffer(ring) << endl;
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
				cout << "������� ������ ��������, ������� ��������� � �����. "
					<< "� ��������� [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
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
					cout << "������� �� ������� ������� " << DequeueBuffer(queue, deleteItem)
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
				cout << "������� ������ ��������, ������� ��������� � �������. "
					<< "� ��������� [" << MIN_VALUE << ", " << MAX_VALUE << "] ";
				EnqueueStack(queue, InputValidation(MIN_VALUE, MAX_VALUE));
				system("cls");
				break;
			}
			case 2:
			{
				if (IsNotEmpty(queue->Output->Size))
				{
					system("cls");
					cout << "������� �� ������� ������� " << DequeueStack(queue)
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
			cout << "��� ���� �����, ��� ��������� ������ �������� ��������� �����\n";
		}

		for (int i = stack->Top; i >= 0; i--)
		{
			cout << "[" << i << "] " << stack->Array[i] << endl;
		}
	}
	else
	{
		cout << "��� ���� ����\n";
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
		cout << "� ����� ������� ��� ��������� " << endl;
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
		cout << "���� ����� �����\n";
	}
}