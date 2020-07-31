#include <bits/stdc++.h>
using namespace std;

int solution(string str, int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (str[0] == '0')
        return 0;

    int cnt = 0;
    if (str[n - 1] > '0')
        cnt = solution(str, n - 1);
    if (str[n - 2] == '1' ||
        (str[n - 2] == '2' && str[n - 1] < '7'))
        cnt += solution(str, n - 2);
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        cout << solution(s, n) << endl;
    }
}