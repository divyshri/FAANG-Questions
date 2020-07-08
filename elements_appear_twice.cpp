#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    cin >> n;
    vector<int> ar;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int indx = abs(ar[i]);
        if (ar[indx - 1] < 0)
        {
            res.push_back(indx);
        }
        else
        {
            ar[indx - 1] *= -1;
        }
    }
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i < res.size() - 1)
            cout << ", ";
    }
    cout << "]";
}