#include <bits/stdc++.h>
using namespace std;

void uniqueString(string str)
{
    int last_index[26] = {0};
    bool isPresent[26] = {0};
    for (int i = 0; i < str.size(); i++)
        last_index[str[i] - 'a'] = i;

    stack<char> stk;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (!isPresent[ch - 'a'])
        {

            while (!stk.empty() && ch < stk.top() && last_index[stk.top() - 'a'] > i)
            {
                isPresent[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(ch);
            isPresent[ch - 'a'] = true;
        }
    }
    int k = stk.size();
    char *res = new char[k + 1];
    res[k--] = '\0';
    while (!stk.empty())
    {
        res[k--] = stk.top();
        stk.pop();
    }
    cout << res << endl;
}

int main()
{
    string s;
    while (cin >> s)
        uniqueString(s);
}