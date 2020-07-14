#include <bits/stdc++.h>
using namespace std;

int check(vector<int> ar)
{
    int n = ar.size();
    for (int i = 0; i < ar.size(); i++)
        if (ar[i] > n + 1 or ar[i] <= 0)
            ar[i] = n + 2;
    for (int i = 0; i < ar.size(); i++)
    {
        int val = ar[i] > 0 ? ar[i] - 1 : -ar[i] - 1;
        if (val >= 0 and val < n)
            ar[val] = -1 * abs(ar[val]);
    }
    for (int i = 0; i < ar.size(); i++)
        if (ar[i] > 0)
            return i + 1;
    return n + 1;
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
    cout << check(ar) << endl;
}
