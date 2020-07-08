#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ar, int start, int end)
{

    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (ar[mid] < ar[mid + 1])
        return solution(ar, mid + 1, end);
    else
        return solution(ar, start, mid);
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
    cout << solution(ar, 0, ar.size() - 1) << endl;
}