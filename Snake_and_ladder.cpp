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

	void shortestPath(int src, int dest) {
		queue<int> q;
		map<int, int> hash_map;
		map<int, int> parent;
		q.push(src);
		for (auto i : l)
			hash_map[i.first] = INT_MAX;
		hash_map[src] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto val : l[node]) {
				if (hash_map[val] == INT_MAX) {
					q.push(val);
					hash_map[val] = hash_map[node] + 1;
					parent[val] = node;
				}
			}
		}
		int z = dest;
		while (z != src) {
			cout << z << " < - ";
			z = parent[z];
		}
		cout << src;

	}
};
int main() {
	Graph g;
	int board[50] = {0};
	board[2] = 13;
	board[5]  = 2;
	board[9] = 18;
	board[18] = 11 ;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
	for (int u = 0; u <= 36; u++)
		for (int dice = 1; dice <= 6; dice++)
			g.addNode(u, u + dice + board[u + dice], false);
	g.shortestPath(0, 36);
}
