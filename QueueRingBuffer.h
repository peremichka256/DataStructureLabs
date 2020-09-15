#pragma once
#include "RingBuffer.h"

struct QueueRingBuffer
{
	RingBuffer* RingBuffer;
};

QueueRingBuffer* CreateQueueBuffer(int size);
void EnqueueBuffer(QueueRingBuffer* queue, int value);
int DequeueBuffer(QueueRingBuffer* queue, int);
void DeleteQueueBuffer(QueueRingBuffer* queue, int size);