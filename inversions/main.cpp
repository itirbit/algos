#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void print(T vec, std::string str = "")
{
	std::cout << str << " ";
	for(auto n : vec)
		std::cout << n << " ";
	std::cout << "\n";
}

std::pair<std::vector<int>, int> countSplitInv(std::vector<int> l, std::vector<int> r)
{
	print(l, "l");
	print(r, "r");
	int n = l.size() + r.size();
	std::vector<int> result(n, 0);
	int i = 0;
	int j = 0; 
	int split = 0;
	for (int k = 0; k < n;  ++k)
	{
		if (i >= l.size())
			result[k] = r[j++];
		else if (j >= r.size())
			result[k] = l[i++];
		else if(l[i] < r[j])
			result[k] = l[i++];
		else
		{
			result[k] = r[j++];
			split += n / 2 - i + 1;
		}
		
	}
	print(result, "split");
	return std::make_pair(result, split);
}


std::pair<std::vector<int>, int> countInv(std::vector<int> vec)
{
	if(vec.size() == 0 || vec.size() == 1)
		return std::make_pair(vec, 0);
	else 
	{
		int m = vec.size() / 2;
		std::vector<int> tlVec(vec.begin(), vec.begin() + m);
		auto [lVec, left] = countInv(tlVec);
		std::vector<int> trVec(vec.begin() + m, vec.end());
		auto [rVec, right] = countInv(trVec);
		auto [sVec, split] = countSplitInv(lVec, rVec);
		return std::make_pair(sVec, left + right + split);
	}
}

void solve(std::vector<int> vec)
{
	std::cout << "array: ";
	print(vec);
	//std::cout << ", new array: ";
	auto [newVec, res] = countInv(vec);
	print(newVec, "new array");
	std::cout << ", inversion: " << res << "\n";
}

int main(int argc, char** argv)
{
	solve({1,3,5,2,4,6});
	return 0;
}
