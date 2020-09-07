#pragma once
#include "CommonFunc.h"

struct BufferNode
{
	int Data;
	bool IsHaveInfo;
	BufferNode* Next;
};

struct RingBuffer
{
	int Size;
	int EmployedMemory;
	int FreeMemory;
	BufferNode* Begin;
	BufferNode* IndexOutput;
	BufferNode* IndexInput;
};

RingBuffer* InitBuffer(int size);
void PushInBuffer(RingBuffer* ring, int value);
int PopFromBuffer(RingBuffer* ring);
void DeleteBuffer(RingBuffer* ring);
int FreeMemoryInfo(RingBuffer* ring);
int EmployedMemoryMemoryInfo(RingBuffer* ring);
void AddNewNode(RingBuffer* ring);