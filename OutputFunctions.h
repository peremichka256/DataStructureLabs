#pragma once
#include "QueueRingBuffer.h"
#include "QueueStack.h"

void MenuText();
//Stack
int PrintMenuStack(Stack* stack);
void PrintMenuStackText();
void ShowStack(Stack* stack);
//RingBuffer
int PrintMenuBuffer(RingBuffer* ring);
void PrintMenuBufferText();
void ShowBuffer(RingBuffer* ring);
//Queue
int PrintMenuQueueBuffer(QueueRingBuffer* queue);
void ShowQueueBuffer(QueueRingBuffer* queue);
int PrintMenuQueueStack(QueueStack*queue);
void ShowQueueStack(QueueStack* queue);
void PrintMenuQueueText();