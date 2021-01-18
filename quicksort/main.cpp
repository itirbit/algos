#include <vector>
#include <iostream>

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
	return l + (r-l)/2; //TODO
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
	std::vector<int> vec = {4,3,5,6,0,9,1,2,7,8};
	print(vec);
	quicksort(vec, 0, vec.size() - 1);
	print(vec);
	return 0;
}
