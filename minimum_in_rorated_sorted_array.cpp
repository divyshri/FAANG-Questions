#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ar)
{
    if (ar[0] < ar[ar.size() - 1])
        return ar[0];
    int start = 0;
    int n = ar.size() - 1;
    int end = ar.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid - 1 >= 0 and ar[mid] < ar[mid - 1])
            return ar[mid];
        else if (ar[mid] > ar[n - 1])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
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