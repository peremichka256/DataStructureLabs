#pragma once

struct TreapNode
{
	int Data;
	int Priority;
	TreapNode* Left;
	TreapNode* Right;
	TreapNode* Parent;
};