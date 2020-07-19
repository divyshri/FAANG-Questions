#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, sum = 0;
    cin >> k;
    int temp;
    queue<int> q;
    while (cin >> temp)
    {
        if (temp == -1)
            break;
        if (q.size() < k)
        {
            q.push(temp);
            sum += temp;
        }
        else
        {
            int t = q.front();
            q.pop();
            q.push(temp);
            sum = sum + temp - t;
        }
        double res = (double)sum / q.size();
        printf("%.4f ", res);
    }
}