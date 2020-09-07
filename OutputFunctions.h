#pragma once
#include "QueueRingBuffer.h"
#include "QueueStack.h"

void MenuText();
//Stack
int MenuStack(Stack* stack);
void MenuStackText();
void ShowStack(Stack* stack);
//RingBuffer
int MenuBuffer(RingBuffer* ring);
void MenuBufferText();
void ShowBuffer(RingBuffer* ring);
//Queue
int MenuQueueBuffer(QueueRingBuffer* queue);
void ShowQueueBuffer(QueueRingBuffer* queue);
int MenuQueueStack(QueueStack*queue);
void ShowQueueStack(QueueStack* queue);
void MenuQueueText();