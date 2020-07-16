#include <bits/stdc++.h>
using namespace std;

int checkThreeSum(vector<int> &ar, int target)
{
    sort(ar.begin(), ar.end());
    int i = 0, near_sum, near_diff = INT_MAX;
    while (i <= ar.size() - 3)
    {
        int j = i + 1;
        int k = ar.size() - 1;
        int sum = ar[i] + ar[j] + ar[k];
        while (j < k)
        {
            if (abs(sum - target) < near_diff)
            {
                near_diff = abs(sum - target);
                near_sum = sum;
            }
            if (target > sum)
            {
                sum -= ar[j++];
                sum += ar[j];
            }
            else if (target < sum)
            {
                sum -= ar[k--];
                sum += ar[k];
            }
            else
                return sum;
        }
        i++;
    }
    return near_sum;
}

int main()
{
    int n, k, temp;
    cin >> n >> k;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    cout << checkThreeSum(ar, k) << endl;
}