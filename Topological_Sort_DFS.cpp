#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph {
	map<int, list<int> > l;
public:
	void addNode(int a, int b, bool bidir = true) {
		l[a].push_back(b);
		if (bidir)
			l[b].push_back(a);
	}
	void printGraph() {
		for (auto x : l) {
			cout << x.first << "->";
			for (auto val : x.second)
			{	cout << val << ", ";
			}
			cout << endl;
		}
	}
	void dfsHelper(int node, map<int, bool> &visited, list<int> &topological) {
		visited[node] = true;
		for (auto val : l[node]) {
			if (!visited[val]) {
				dfsHelper(val, visited, topological);
			}
		}
		topological.push_front(node);
	}

	void dfsTopologicalSort(int src) {
		map<int, bool> visited;
		list<int> topological;
		dfsHelper(src, visited, topological);
		for (auto val : topological) {
			cout << val << " -> ";
		}

	}
};
int main() {
	Graph g;
	g.addNode(1, 2, false);
	g.addNode(1, 3, false);
	g.addNode(2, 4, false);
	g.addNode(3, 4, false);


	g.dfsTopologicalSort(1);


}
