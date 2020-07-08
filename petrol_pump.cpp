#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &petrol, vector<int> &cost)
{
    int cur = 0;
    int start = 0;
    for (int i = 0; i < petrol.size(); i++)
    {
        cur += petrol[i] - cost[i];
        if (cur < 0)
        {
            cur = 0;
            start = i + 1;
        }
    }
    return start;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp;
    cin >> n;
    vector<int> petrol, cost;
    int total_petrol = 0, total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        petrol.push_back(temp);
        total_petrol += temp;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cost.push_back(temp);
        total_cost += temp;
    }
    if (total_petrol - total_cost < 0)
        cout << "-1" << endl;
    else
    {
        cout << solution(petrol, cost) << endl;
    }
}