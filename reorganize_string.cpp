#include <bits/stdc++.h>
using namespace std;

string solution(string s)
{
    int ar[26] = {0};
    for (int i = 0; i < s.size(); i++)
        ar[s[i] - 'a']++;
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
    {
        if (ar[i] > 0)
            pq.push(make_pair(ar[i], (char)i + 'a'));
    }
    string ans = "";
    while (!pq.empty())
    {
        if (pq.size() >= 2)
        {
            pair<int, char> p1;
            pair<int, char> p2;
            p1 = pq.top();
            pq.pop();
            p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;

            p1.first--;
            p2.first--;
            if (p1.first > 0)
                pq.push(p1);
            if (p2.first > 0)
                pq.push(p2);
        }
        else if (pq.size() == 1)
        {
            if (pq.top().first > 1)
                return "";
            else
            {
                ans += pq.top().second;
                pq.pop();
            }
        }
    }
    return ans;
}

int main()
{
    char ch;
    cin >> ch;
    cin >> ch;
    string s;
    cin >> s;
    int n = s.size();
    string str = s.substr(1, n - 2);
    //cout << str << endl;
    cout << solution(s) << endl;
}