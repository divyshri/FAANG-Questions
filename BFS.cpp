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
	void bfs(int src) {
		queue<int> q;
		map<int, bool> visited;
		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			int node = q.front();
			cout << node << " -> ";
			q.pop..
			();
			for (auto x : l[node]) {
				if (!visited[x]) {
					q.push(x);
					visited[x] = true;
				}
			}
		}
	}
};
int main() {
	Graph g;
	g.addNode(0, 4);
	g.addNode(0, 1);
	g.addNode(1, 4);
	g.addNode(4, 3);
	g.addNode(1, 3);
	g.addNode(1, 2);
	g.addNode(2, 3);
	g.bfs(0);

}
