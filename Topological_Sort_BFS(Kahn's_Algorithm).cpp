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
	void bfsTopologicalSort() {
		map<int, bool> visited;
		map<int, int> indegree;
		queue<int> q;
		for (auto val : l) {
			indegree[val.first] = 0;
			visited[val.first] = false;
		}

		for (auto x : l)
			for (auto val : x.second)
				indegree[val]++;


		for (auto x : l)
			if (indegree[x.first] == 0)
				q.push(x.first);

		while (!q.empty()) {
			int node = q.front();
			cout << node << endl;
			q.pop();
			for (auto val : l[node]) {
				indegree[val]--;
				if (indegree[val] == 0)
					q.push(val);
			}
		}

	}
};
int main() {
	Graph g;
	g.addNode(0, 2, false);
	g.addNode(1, 2, false);
	g.addNode(1, 4, false);
	g.addNode(2, 4, false);
	g.addNode(2, 3, false);
	g.addNode(3, 5, false);
	g.addNode(4, 5, false);
	//g.printGraph();
	cout << endl << endl;

	g.bfsTopologicalSort();


}
