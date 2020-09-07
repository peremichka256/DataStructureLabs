#include "RingBuffer.h"

RingBuffer* InitBuffer (int size)
{
	srand(time(nullptr));

	RingBuffer* ring = new RingBuffer;
	ring->Size = size;
	BufferNode* current = nullptr;

	for (int i = 0; i < ring->Size; i++)
	{
		BufferNode* newItem = new BufferNode;
		newItem->Data = rand() % 100;
		newItem->IsHaveInfo = true;

		if (i == 0)
		{
			ring->Begin = newItem;
			current = ring->Begin;
		}
		else if (i == size - 1)
		{
			current->Next = newItem;
			current = newItem;
			current->Next = ring->Begin;
		}
		else
		{
			current->Next = newItem;
			current = newItem;
		}
	}
	ring->EmployedMemory = size;
	ring->FreeMemory = 0;
	ring->IndexInput = ring->IndexOutput = ring->Begin;
	return ring;
}

void PushInBuffer(RingBuffer* ring, int value)
{
	if (IsNotEmpty(ring->Size))
	{
		ring->IndexInput->IsHaveInfo = true;
		ring->IndexInput->Data = value;
		ring->IndexInput = ring->IndexOutput = ring->IndexInput->Next;

		if (ring->FreeMemory != 0)
		{
			ring->FreeMemory--;
			ring->EmployedMemory++;
		}
	}
}

int PopFromBuffer(RingBuffer* ring)
{
	if (IsNotEmpty(ring->EmployedMemory))
	{
		while (ring->IndexOutput->IsHaveInfo != true)
		{
			ring->IndexOutput = ring->IndexOutput->Next;
		}
		ring->IndexOutput->IsHaveInfo = false;
		ring->FreeMemory++;
		ring->EmployedMemory--;
	}
	return ring->IndexOutput->Data;
}

void DeleteBuffer(RingBuffer* ring)
{
	for (int i = 0; i < ring->Size; i++)
	{
		BufferNode* current = ring->Begin;
		ring->Begin = current->Next;
		delete current;
	}
	delete ring;
}

void AddNewNode(RingBuffer* ring)
{
	BufferNode* newItem = new BufferNode;

	if (ring->IndexInput->IsHaveInfo == true)
	{
		ring->IndexInput->IsHaveInfo = false;
		newItem->IsHaveInfo = true;
	}
	else
	{
		newItem->IsHaveInfo = false;
	}
	newItem->Data = ring->IndexInput->Data;
	newItem->Next = ring->IndexInput->Next;
	ring->IndexInput->Next = newItem;
	ring->Size++;
	ring->FreeMemory++;
}

int FreeMemoryInfo(RingBuffer* ring)
{
	return ring->FreeMemory;
}

int EmployedMemoryMemoryInfo(RingBuffer* ring)
{
	return ring->EmployedMemory;
}