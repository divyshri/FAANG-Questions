#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>> &ar)
{
}

int main()
{
    int row, col, t;
    cin >> row >> col;
    vector<vector<int>> ar;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            cin >> t;
            temp.push_back(t);
        }
        ar.push_back(temp);
    }
    cout << minimumPathSum(ar) << endl;
}