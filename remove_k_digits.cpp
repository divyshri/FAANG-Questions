#include <bits/stdc++.h>
using namespace std;

string removeK(string num, int k)
{
    string res;
    for (auto val : num)
    {
        while (res.size() and val < res.back() and k)
        {
            res.pop_back();
            k--;
        }
        res.push_back(val);
    }
    while (res.size() and k)
    {
        res.pop_back();
        k--;
    }
    while (res[0] == '0')
        res.erase(0, 1);
    if (res.size() == 0)
        return "0";
    return res;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << removeK(s, k) << endl;
}