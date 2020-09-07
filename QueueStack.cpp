#include "QueueStack.h"
#include "OutputFunctions.h"

QueueStack* CreateQueueStack(int size)
{
	srand(time(nullptr));

	QueueStack* queue = new QueueStack;
	queue->Input = CreateStack(size);
	queue->Output = CreateStack(size);

	for (int i = 0; i < size; i++)
	{
		queue->Input->Array[i] = rand() % 100;
	}
	SwapStack(queue->Input, queue->Output);
	return queue;
}

void SwapStack(Stack* copiedStack, Stack* secondStack)
{
	int j = 0;

	for (int i = secondStack->Top; i >= 0 ; --i)
	{
		secondStack->Array[j] = copiedStack->Array[i];
		j++;
	}
}

void EnqueueStack(QueueStack* queue, int value)
{
	int temp = queue->Input->Top;
	temp++;

	if (temp == queue->Input->Size)
	{
		AddCell(queue->Input);
		AddCell(queue->Output);
	}
	Push(queue->Input, value);
	queue->Output->Top++;
	SwapStack(queue->Input, queue->Output);
}

int DequeueStack(QueueStack* queue)
{
	int popItem = Pop(queue->Output);
	queue->Input->Top--;
	SwapStack(queue->Output, queue->Input);
	return popItem;
}

void DeleteQueueStack(QueueStack* queue, int size)
{
	DeleteStack(queue->Input);
	DeleteStack(queue->Output);
	delete queue;
}