#pragma once
#include <vector>

class Heap
{
public:
	void push(int val);
	int extract();
	void print();

private:
	void siftDown();
	void siftUp();

	std::vector<int> v;
};

