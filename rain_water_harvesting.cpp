#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int> ar)
{
    int n = ar.size();
    vector<int> left(n, 0);
    for (int i = 1; i < ar.size(); i++)
    {
        left[i] = max(left[i - 1], ar[i - 1]);
    }
    vector<int> right(n, 0);
    for (int i = ar.size() - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], ar[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        int k = min(left[i], right[i]);
        if (k - ar[i] > 0)
            ans += k - ar[i];
    }
    return ans;
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
    cout << rainWater(ar) << endl;
}