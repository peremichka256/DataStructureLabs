#pragma once
#include "RingBuffer.h"

struct QueueRingBuffer
{
	RingBuffer* RingBuffer;
};

QueueRingBuffer* CreateQueueBuffer(int size);
void EnqueueBuffer(QueueRingBuffer*, int value);
int DequeueBuffer(QueueRingBuffer*, int);
void DeleteQueueBuffer(QueueRingBuffer*, int size);