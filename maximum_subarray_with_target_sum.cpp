#include <bits/stdc++.h>
using namespace std;
int checkSubarraySum(vector<int> &nums, int k)
{
    vector<int> prefixSum;
    unordered_map<int, int> mp;
    prefixSum.push_back(0);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        prefixSum.push_back(sum);
    }
    for (int i = 0; i < prefixSum.size(); i++)
    {
        mp[prefixSum[i]] = i;
    }
    int ans = -1;
    for (int i = 0; i < prefixSum.size(); i++)
    {
        if (mp.find(k + prefixSum[i]) != mp.end())
        {
            int index = mp[k + prefixSum[i]];
            ans = max(index - i, ans);
        }
    }
    return ans;
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
        bool flag = false;
        while (s[i] != ',' && s[i] != ']')
        {
            if (s[i] == '-')
            {
                flag = true;
                i++;
            }
            x = x * 10 + (s[i] - '0');
            if (flag)
                x = x * -1;
            i++;
        }
        v.push_back(x);
    }
    /*for(auto val:v)
        cout<<val<<" ";*/
    int k;
    cin >> k;
    cout << checkSubarraySum(v, k) << endl;
}