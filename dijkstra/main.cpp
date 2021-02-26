#include <vector>
#include <queue>
#include <map>

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
		{5, {4,6} }
	};	
	return m;
}

std::map<int, std::map<int, int>> createDistances()
{
	std::map<int, std::map<int, int>> m = {
		{1, {{2,7}, {3,9}, {6,14}} },
		{2, {{1,7}, {3,10}, {4,15} }},
		{3, { } }
	};	
	return m;
}

int main()
{
	std::vector<Graph*> g;
	for(int i = 0; i < 5; ++i)
	{
		auto graph = new Graph;
		graph->id = i;
		graph->neighbours = g;
		g.push_back(graph);
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



