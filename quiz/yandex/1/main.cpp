#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;


string toString(vector<int>& nums)
{
	string res;
	unordered_map<int, pair<int,int>> peaks;
	map<int, string> m;
	for(int n : nums)
	{
		int diff[] = {-1,1};
		bool hasNeighbours = false;
		for (int i = 0; i < 2; ++i)
		{
			int neighbour = n + diff[i];
			if (peaks.find(neighbour) != peaks.end())
			{
				auto [minVal, maxVal] = peaks[neighbour];
				minVal = min(n, minVal);
				maxVal = max(n, maxVal);
				peaks.erase(neighbour);
				peaks[minVal] = make_pair(minVal, maxVal);
				peaks[maxVal] = make_pair(minVal, maxVal);
				hasNeighbours = true;
			}		
		}
		if (!hasNeighbours)
		{
			peaks[n] = make_pair(n,n);
		}
	}
	for (auto [_, entry] : peaks)
	{
		auto [minVal, maxVal] = entry;
		string s = minVal == maxVal ? to_string(minVal) : to_string(minVal) + "-" + to_string(maxVal);
		m[minVal] = s;
	}
	for(auto [_, s] : m)
	{
		res += s + ",";
	}
	if (!res.empty())
		res.pop_back();
	return res;
}

template <typename... Args>
void check(Args... args)
{
	vector<int> v;
	(v.push_back(args), ...);
	for(auto i : v)
		cout << i << " ";
	cout << "\n";
	cout << toString(v);
}

int main()
{	
	check(3,1,0,2,8,11,9,99,5,6,4);
}


