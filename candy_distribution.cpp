#include <bits/stdc++.h>
using namespace std;

int candies(vector<int> ar)
{
    int sum = 0;
    int n = ar.size();
    int ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = 1;
    for (int i = 1; i < ar.size(); i++)
    {
        if (ar[i] > ar[i - 1])
        {
            ans[i] = ans[i - 1] + 1;
        }
    }
    for (int i = ar.size() - 2; i >= 0; i--)
    {
        if (ar[i] > ar[i + 1] and ans[i] <= ans[i + 1])
        {
            ans[i] = ans[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; i++)
        //cout<<ans[i]<<" ";
        sum += ans[i];
    return sum;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    cout << candies(ar) << endl;
}
