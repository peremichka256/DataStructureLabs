#pragma once
#include "Stack.h"

struct QueueStack
{
	Stack* Input;
	Stack* Output;
};

QueueStack* CreateQueueStack(int size);
void EnqueueStack(QueueStack*, int value);
int DequeueStack(QueueStack*);
void DeleteQueueStack(QueueStack*, int);
void SwapStack(Stack* cpiedStack, Stack* secondStack);