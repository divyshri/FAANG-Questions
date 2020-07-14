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
	void bfs_detect_cycle(int src) {
		map<int, bool> visited;
		map<int, int> parent;
		queue<int> q;
		q.push(src);
		visited[src] = true;
		parent[src] = src;
		bool flag = false;
		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();
			for (auto val : l[node]) {
				if (!visited[val]) {
					q.push(val);
					visited[val] = true;
					parent[val] = node;
				}
				else if (val != parent[node]) {
					flag = true;
					break;
				}

			}
		}
		(flag) ? cout << "Cycle is Present" << endl : cout << "Cycle is not present" << endl;

	}
};
int main() {
	/*Graph g;
	g.addNode(0, 1);
	g.addNode(0, 4);
	g.addNode(1, 2);
	g.addNode(2, 4);
	g.addNode(4, 3);
	g.addNode(2, 3);
	g.addNode(5, 3);
	//g.printGraph();
	cout << endl << endl;

	g.bfs_detect_cycle(0);
	*/
	Graph G;
	G.addNode(1, 2);
	G.addNode(1, 3);
	G.addNode(3, 4);
	G.printGraph();
	G.bfs_detect_cycle(1);

}
