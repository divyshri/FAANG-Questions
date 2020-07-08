#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &ar)
{

    map<int, int> mp;
    int sum = 0;
    mp[0]++;
    for (int i = 0; i < ar.size(); i++)
    {
        sum += ar[i];
        mp[sum]++;
    }
    int count = 0;
    for (auto val : mp)
    {
        if (val.second > 1)
        {
            count += val.second * (val.second - 1) / 2;
        }
    }
    return count;
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
    cout << solution(ar) << endl;
}