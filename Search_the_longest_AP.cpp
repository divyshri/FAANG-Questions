#include <bits/stdc++.h>
using namespace std;
int longestAP(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;
    map<int, list<int>> mp;
    int res = 2;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {

            int d = nums[j] - nums[i];
            int count = 2;
            int pos = j;
            int no = nums[j] + d;
            while (mp.find(no) != mp.end())
            {
                bool flag = false;
                for (auto node : mp[no])
                {
                    if (node > pos)
                    {
                        count++;
                        no += d;
                        pos = node;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            res = max(res, count);
        }
    }
    return res;
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
    cout << longestAP(v) << endl;
}