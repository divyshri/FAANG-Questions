#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ar, int max_v, int m)
{
    sort(ar.begin(), ar.end());
    int min_v = max_v + 1;
    for (int i = 0; i <= ar.size() - m; i++)
    {
        int indx = i + m - 1;
        min_v = min((ar[indx] - ar[i]), min_v);
    }
    return min_v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp;
        cin >> n;
        vector<int> ar;
        int max_v = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            ar.push_back(temp);
            max_v = max(max_v, temp);
        }
        int m;
        cin >> m;
        cout << solution(ar, max_v, m) << endl;
    }
}