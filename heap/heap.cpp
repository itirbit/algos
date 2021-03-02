#include <vector>
#include <iostream>
#include "heap.h"

void Heap::push(int val)
{
	v.push_back(val);
	siftUp();
}

int Heap::extract()
{
	int res = v.front();
	std::swap(v.front(), v.back());
	v.pop_back();
	siftDown();
	return res;
}

void Heap::print()
{
	for(int i : v)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

void Heap::siftDown()
{	
	if (v.empty())
		return;
	int p = 0;
	while(2*p + 1 < v.size())
	{
		int l = p*2 + 1;
		int r = p*2 + 2;
		int toSwap = l;
		if (r < v.size() && v[r] < v[l])
		{
			toSwap = r;
		}
		if (v[p] <= v[toSwap])
		{
			break;
		}
		std::swap(v[p], v[toSwap]);
		p = toSwap;
	}
}

void Heap::siftUp()
{
	if (v.size() == 1)
		return;
	int id = v.size()-1;
	int p = (id-1)/2;
	while(v[id] < v[p])
	{
		std::swap(v[id], v[p]);
		id = (id-1)/2;
		p = (id-1)/2;
	}
}	

