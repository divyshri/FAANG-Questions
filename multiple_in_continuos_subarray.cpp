#include <bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;
    int sum = 0;
    mp[0] = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (k != 0)
        {
            sum += nums[i];
            int mod = sum % k;
            if (mp.find(mod) == mp.end())
                mp[mod] = i;
            else if (i - mp[mod] > 1)
                return true;
        }
        else if (k == 0 and nums[i] == 0 and i < nums.size() - 1 and nums[i + 1] == 0)
            return true;
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    vector<int> v;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        int x = 0;
        while (s[i] != ',' && s[i] != ']')
        {
            x = x * 10 + (s[i] - '0');
            i++;
        }
        v.push_back(x);
    }
    int k;
    cin >> k;

    if (checkSubarraySum(v, k))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}