#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, list<int>> adj;
    int count = 0;
    void addNode(int a, int b)
    {
        adj[a].push_back(b);
        adj[a].sort();
        adj[a].unique();
    }

    void pathHelper(int node, int dest, map<int, bool> &visited)
    {

        visited[node] = true;
        if (node == dest)
        {
            visited[node] = false;
            count++;
            return;
        }
        for (auto val : adj[node])
        {
            if (!visited[val])
                pathHelper(val, dest, visited);
        }
        visited[node] = false;
    }

    void countPath(int src, int dest)
    {
        map<int, bool> visited;
        visited[src] = true;
        for (auto val : adj[src])
        {
            if (!visited[val])
                pathHelper(val, dest, visited);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e, a, b;
        cin >> v >> e;
        Graph G;
        for (int i = 0; i < v; i++)
        {
            list<int> temp;
            G.adj[i] = temp;
        }
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            G.addNode(a, b);
        }
        int s, d;
        cin >> s >> d;

        if (s == d)
            cout << 1 << endl;
        else
        {
            G.countPath(s, d);
            cout << G.count << endl;
        }
    }
}