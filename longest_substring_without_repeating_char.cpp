#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string str)
{
    map<char, int> mp;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (mp.find(ch) != mp.end())
        {
            j = max(mp[ch] + 1, j);
        }
        ans = max(ans, i - j + 1);
        mp[ch] = i;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << longestSubstring(s) << endl;
    }
}