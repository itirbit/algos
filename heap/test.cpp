#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "heap.h"

int main(int argc, char** argv)
{
	std::vector<int> v1;
	std::vector<int> v2;
	std::fstream fs;
	fs.open("../randomInput/input.txt", std::fstream::in);
	if (fs.is_open())
	{
		std::string line;
		while(getline(fs, line, ' '))
		{
			v1.push_back(std::stoi(line));
			v2.push_back(std::stoi(line));
		}
	}
	fs.close();
	Heap heap;
	for(int i : v1)
		heap.push(i);
	
	std::make_heap(v2.begin(), v2.end(), std::greater<>{});
	while(!v2.empty())
	{
		int minHeap = heap.extract();
		std::pop_heap(v2.begin(), v2.end(),std::greater<>{});
		int minStd = v2.back();
		v2.pop_back();
		if (minStd != minHeap)
		{
			std::cout << "FAIL\n";
			return 1;
		}
	}

	std::cout << "OK\n";
	return 0;
}
