#pragma once
#include "Stack.h"

struct QueueStack
{
	Stack* Input;
	Stack* Output;
};

QueueStack* CreateQueueStack(int size);
void EnqueueStack(QueueStack* queue, int value);
int DequeueStack(QueueStack* queue);
void DeleteQueueStack(QueueStack* queue, int size);
void SwapStack(Stack* cpiedStack, Stack* secondStack);