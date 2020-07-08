#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &s, vector<int> &e)
{
    int ss = 0;
    int ee = 0;
    int res = 0;
    int count = 0;
    while (ss < s.size() and ee < e.size())
    {
        if (s[ss] < e[ee])
        {
            ss++;
            count++;
        }
        else
        {
            ee++;
            count--;
        }
        res = max(res, count);
    }
    return res;
}

int main()
{
    int n, x, y;
    cin >> n;
    vector<int> s, e;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push_back(x);
        cin >> y;
        e.push_back(y);
    }
    sort(s.begin(), s.end());
    sort(e.begin(), e.end());
    cout << solution(s, e) << endl;
}