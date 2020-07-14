#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n)
{
    string s = to_string(n);
    bool v = next_permutation(s.begin(), s.end());
    if (v == false)
        return -1;
    else
    {
        //cout<<s<<endl;
        long long int num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            num = num * 10 + (s[i] - '0');
        }
        if (log2(num) + 1 > 32)
            return -1;
        return num;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<nextGreaterElement(n)<<endl;
}