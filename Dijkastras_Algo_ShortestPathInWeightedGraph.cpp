#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
	unordered_map<T, list<pair<T, int> > > adj_list;
public:
	void addNode(T u, T v, int dis, bool bidir = true) {
		adj_list[u].push_back(make_pair(v, dis));
		if (bidir)
			adj_list[v].push_back(make_pair(u, dis));
	}
	void print_graph() {
		for (auto x : adj_list) {
			cout << x.first << "->";
			for (auto val : x.second) {
				cout << " (" << val.first << " dist = " << val.second << "),";
			}
			cout << endl;
		}
	}
	void dijkastra() {
		unordered_map<T, int> dist;
		for (auto x : adj_list) {
			dist[x.first] = INT_MAX;
		}

		set<pair<T, int> > s;
		dist[src] = 0;
		s.insert(make_pair(src, 0));
		while (!s.empty()) {

		}
	}


};
int main() {
	Graph<int> G;
	G.addNode(1, 2, 1);
	G.addNode(1, 3, 4);
	G.addNode(1, 4, 7);
	G.addNode(2, 3, 1);
	G.addNode(3, 4, 2);
	G.print_graph();
}
