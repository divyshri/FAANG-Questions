#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> ar)
{
    int row = ar.size();
    int col = ar[0].size();
    int dp[row + 1][col + 1] = {0};
    int res = 0;
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (ar[i - 1][j - 1] == 1)
            {
                int k = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] = k + 1;
                res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return res * res;
}

int main()
{
    int a, b, temp;
    cin >> a >> b;
    vector<vector<int>> ar;
    for (int i = 0; i < a; i++)
    {
        vector<int> t;
        for (int i = 0; i < b; i++)
        {
            cin >> temp;
            t.push_back(temp);
        }
        ar.push_back(t);
    }
    cout << solution(ar) << endl;
}