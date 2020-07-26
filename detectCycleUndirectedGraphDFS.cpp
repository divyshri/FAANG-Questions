#include <bits/stdc++.h>
#include <list>
using namespace std;
class Graph
{
	map<int, list<int>> l;

public:
	void addNode(int a, int b, bool bidir = true)
	{
		l[a].push_back(b);
		if (bidir)
			l[b].push_back(a);
	}
	void printGraph()
	{
		for (auto x : l)
		{
			cout << x.first << "->";
			for (auto val : x.second)
			{
				cout << val << ", ";
			}
			cout << endl;
		}
	}
	bool dfsCyclicHelper(int node, map<int, bool> &visited, int parent)
	{
		visited[node] = true;
		bool flag = false;
		for (auto val : l[node])
		{
			if (!visited[val])
				flag = dfsCyclicHelper(val, visited, node);
			else if (val != parent)
				flag = true;
		}
		return flag;
	}
	bool dfsCyclic()
	{
		map<int, bool> visited;
		bool flag = false;
		for (auto val : l)
		{
			if (!visited[val.first])
			{
				flag = dfsCyclicHelper(val.first, visited, val.first);
			}
		}
		return flag;
	}
};
int main()
{
	Graph g;
	g.addNode(1, 2);
	g.addNode(1, 4);
	g.addNode(2, 3);
	g.addNode(4, 3);

	if (g.dfsCyclic())
		cout << "Cycle Present" << endl;
	else
		cout << "Cycle Not Present" << endl;
}
