#include "QueueRingBuffer.h"

QueueRingBuffer* CreateQueueBuffer(int size)
{
	srand(time(nullptr));

	RingBuffer* ring = new RingBuffer;
	QueueRingBuffer* queue = new QueueRingBuffer;
	queue->RingBuffer = ring;
	queue->RingBuffer->Size = size;
	BufferNode* current = nullptr;

	for (int i = 0; i < queue->RingBuffer->Size; i++)
	{
		BufferNode* newItem = new BufferNode;
		newItem->Data = rand() % 100;
		newItem->IsHaveInfo = true;

		if (i == 0)
		{
			queue->RingBuffer->IndexOutput = newItem;
			current = queue->RingBuffer->IndexOutput;
			current->Next = current;
			queue->RingBuffer->Begin = current;
		}
		else if (i == size - 1)
		{
			current->Next = newItem;
			current = newItem;
			current->Next = queue->RingBuffer->IndexOutput;
			queue->RingBuffer->Begin = current;
		}
		else
		{
			current->Next = newItem;
			current = newItem;
		}
	}
	queue->RingBuffer->IndexInput = nullptr;
	queue->RingBuffer->EmployedMemory = queue->RingBuffer->FreeMemory = 0;
	return queue;
}

void EnqueueBuffer(QueueRingBuffer* queue, int value)
{
	BufferNode* newItem = new BufferNode;
	newItem->Data = value;
	newItem->IsHaveInfo = true;
	BufferNode* current = nullptr;

	if (IsNotEmpty(queue->RingBuffer->Size))
	{
		current = queue->RingBuffer->Begin;
		current->Next = newItem;
		newItem->Next = queue->RingBuffer->IndexOutput;
		queue->RingBuffer->Begin = newItem;
	}
	else
	{
		queue->RingBuffer->Begin = newItem;
		current = queue->RingBuffer->Begin;
		current->Next = queue->RingBuffer->IndexOutput;
		queue->RingBuffer->IndexOutput = current;
	}
	queue->RingBuffer->Size++;
}

int DequeueBuffer(QueueRingBuffer* queue, int deleteItem)
{
	BufferNode* removeItem = queue->RingBuffer->IndexOutput;
	queue->RingBuffer->IndexOutput = removeItem->Next;
	queue->RingBuffer->Size--;
	deleteItem = removeItem->Data;
	queue->RingBuffer->Begin->Next = queue->RingBuffer->IndexOutput;
	delete removeItem;
	return deleteItem;
}

void DeleteQueueBuffer(QueueRingBuffer* queue, int size)
{
	for (int i = 0; i < size; i++)
	{
		int deleteItem = 0;
		DequeueBuffer(queue, deleteItem);
	}
	queue->RingBuffer->Begin = nullptr;
	delete queue;
}