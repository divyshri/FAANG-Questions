#include <bits/stdc++.h>
using namespace std;

/*
int maxProduct(vector<int>& ar) {
        int maxProd = ar[0];
        int minProd = ar[0];
        int res = ar[0];
        for(int i=1;i<ar.size();i++){
            int p1 = maxProd*ar[i];
            int p2 = minProd*ar[i];
            maxProd = max(ar[i],max(p1,p2));
            minProd = min(ar[i],min(p1,p2));
            res = max(maxProd,res);
        }
        return res;
    }
*/

int solution(vector<int> ar)
{
    if (ar.size() == 1)
        return ar[0];
    int pp = 1;
    int np = 1;
    int ans = INT_MIN;
    bool hasZero = false, hasPos = false;
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] > 0)
        {
            hasPos = true;
            pp *= ar[i];
            if (np != 1)
                np *= ar[i];
        }
        else if (ar[i] < 0)
        {
            int temp = pp;
            pp = max(1, np * ar[i]);
            np = temp * ar[i];
        }
        else
        {
            hasZero = true;
            np = pp = 1;
        }
        if (ans < pp)
            ans = pp;
    }
    if (ans == 1)
    {
        if (hasPos)
            return ans;
        if (hasZero)
            return 0;
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
    cout << solution(ar) << endl;
}