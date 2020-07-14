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
	bool dfsCyclicHelper(int node, map<int, bool> &visited, map<int, bool> &stk) {
		visited[node] = true;
		stk[node] = true;
		for (auto val : l[node]) {
			if ((!visited[node] and dfsCyclicHelper(val, visited, stk)) or stk[val])
				return true;
		}
		return false;
	}


	bool dfsCyclic() {
		map<int, bool> visited;
		map<int, bool> stk;
		bool flag = false;
		for (auto val : l) {
			if (!visited[val.first]) {
				flag = dfsCyclicHelper(val.first, visited, stk);
			}
		}
		return flag;
	}
};
int main() {
	Graph g;
	g.addNode(0, 1, false);
	g.addNode(0, 3, false);
	g.addNode(1, 2, false);
	g.addNode(3, 4, false);

	if (g.dfsCyclic())
		cout << "Cycle Present" << endl;
	else
		cout << "Cycle Not Present" << endl;

}
