#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

struct Graph
{
	int id {};
	bool visited {false};
	std::vector<Graph*> neighbours;
};

void cleanUp(std::vector<Graph*>& v)
{
	for(auto g : v)
		delete g;
}

std::map<int,std::vector<int>> createNeighbours()
{
	std::map<int, std::vector<int>> m = {
		{1, {2,3,6} },
		{2, {1,3,4} },
		{3, {1,2,4,6} },
		{4, {2,3} },
		{5, {4,6} },
		{6, {1,3,5}}
	};	
	return m;
}

std::map<int, std::map<int, int>> createDistances()
{
	std::map<int, std::map<int, int>> m = {
		{1, {{2,7}, {3,9}, {6,14}} },
		{2, {{1,7}, {3,10}, {4,15} }},
		{3, {{1,9}, {2,10}, {4,11}, {6,2} } },
		{4, {{2,15}, {3,11}, {5,6} }},
		{5, {{4,6}, {6,9}}}
	};	
	return m;
}

int main()
{
	std::vector<Graph*> g;
	auto neigh = createNeighbours();
	auto dist = createDistances();
	for(auto [id, nvec] : neigh)
	{
		auto graph = new Graph;
		graph->id = id;
		g.push_back(graph);
	}
	for(auto [id, nvec] : neigh)
	{
		auto it = std::find_if(g.begin(), g.end(),[id](auto gr){ return gr->id == id;});
		if (it == g.end())
		{
			std::cerr << "failed to dereference graph iterator\n";
			return 1;
		}
		auto graph = *it;
		for(auto n : nvec)
		{			
			auto nit = std::find_if(g.begin(), g.end(),[n](auto gr){ return gr->id == n;});
			if (nit == g.end())
			{
				std::cerr << "failed to dereference neigbour of graph iterator\n";
				return 1;
			}
			graph->neighbours.push_back(*nit);
		}
	}


	std::queue<Graph*> q;
	q.push(g.front());
	while(!q.empty())
	{
		auto graph = q.front();
		q.pop();
		if (graph->visited)
			continue;
		graph->visited = true;		
	}
	
	cleanUp(g);
}



