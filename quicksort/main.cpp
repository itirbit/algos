#include <vector>
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
void print(T arr)
{
	for(auto n : arr)
	{
		std::cout << n << " ";
	}
	std::cout << "\n";
}

int getPivot(int l, int r)
{
	srand(time(NULL));
	int p = l + rand() % (r-l);
	return p; 
}

int partition(std::vector<int>& v, int first, int last)
{
	int lower = first + 1;
	for (int i = first + 1; i <= last; ++i)
	{
		if (v[i] < v[first])
		{
			std::swap(v[i],v[lower++]);
		}
	}
	std::swap(v[first], v[lower - 1]);
	return lower - 1;
}

void quicksort(std::vector<int>& v, int first, int last)
{
	if (first >= last)
		return;
	int p = getPivot(first,last);
	std::swap(v[p],v[first]);
	int pos = partition(v, first, last);
	quicksort(v, first, pos - 1);
	quicksort(v, pos + 1, last);

}

int main(int argc, char** argv)
{
	std::vector<int> vec;
	std::fstream fs;
	fs.open("../randomInput/input.txt", std::fstream::in);
	if (fs.is_open())
	{
		std::string line;
		while(getline(fs, line, ' '))
		{
			vec.push_back(std::stoi(line));
		}
	}
	else return 1;
	fs.close();
	print(vec);
	quicksort(vec, 0, vec.size() - 1);
	print(vec);
	return 0;
}
