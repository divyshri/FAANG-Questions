#include <bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2)
{
    return stoi(s1 + s2) > stoi(s2 + s1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s[n], temp;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        //cout<<stoi(s[0]);
        sort(s, s + n, compare);
        //reverse(s,s+n);
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
}