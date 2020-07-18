#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> &ar)
{
    stack<int> stk;
    for (int i = 0; i < ar.size(); i++)
    {
        if (!stk.empty() and stk.top() > 0 and ar[i] < 0)
        {
            bool flag = true;
            while (!stk.empty() and stk.top() > 0 and ar[i] < 0)
            {
                if (abs(stk.top()) == abs(ar[i]))
                {
                    stk.pop();
                    flag = false;
                    break;
                }

                else if (abs(ar[i]) > abs(stk.top()))
                {
                    stk.pop();
                    flag = true;
                }
                else if (abs(ar[i]) < abs(stk.top()))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                stk.push(ar[i]);
        }
        else
            stk.push(ar[i]);
    }
    stack<int> res;
    while (!stk.empty())
    {
        res.push(stk.top());
        stk.pop();
    }
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
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

    solution(ar);
}