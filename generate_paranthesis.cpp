#include <bits/stdc++.h>
using namespace std;

void solution(int n, int open, int close, vector<string> &res, string s = "")
{

    if (close == n)
    {
        res.push_back(s);
    }
    if (open > close)
    {
        s.push_back(')');
        solution(n, open, close + 1, res, s);
        s.pop_back();
    }
    if (open < n)
    {
        s.push_back('(');
        solution(n, open + 1, close, res, s);
        s.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> res;
    solution(n, 0, 0, res);
    for (auto val : res)
        cout << val << endl;
}