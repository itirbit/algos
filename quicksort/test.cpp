#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "quicksort.h"

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
	quicksort(v1, 0, v1.size() - 1);
	std::sort(v2.begin(), v2.end());
	if (v1 == v2)
		std::cout << "OK\n";
	else
		std::cout << "Failed\n";
	return 0;
}
