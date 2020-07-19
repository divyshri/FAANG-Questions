#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    int n = T.size();
    vector<int> res(n);
    stack<int> stk;
    for (int i = 0; i < T.size(); i++)
    {
        while (!stk.empty() and T[stk.top()] < T[i])
        {
            int indx = stk.top();
            res[indx] = i - indx;
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    vector<int> ans = dailyTemperatures(ar);
    for (auto val : ans)
        cout << val << " ";
}