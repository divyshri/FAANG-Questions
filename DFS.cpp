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
	void dfsHelper(int node, map<int, bool> &visited) {
		visited[node] = true;
		cout << node << "-> ";
		for (auto val : l[node]) {
			if (!visited[val]) {
				dfsHelper(val, visited);
			}
		}
	}

	void dfs(int src) {
		map<int, bool> visited;
		dfsHelper(src, visited);
	}
};
int main() {
	Graph g;
	g.addNode(0, 4);
	g.addNode(2, 3);
	g.addNode(1, 2);
	g.addNode(2, 4);
	g.addNode(3, 5);
	g.addNode(0, 1);
	g.addNode(4, 3);

	g.dfs(0);


}
