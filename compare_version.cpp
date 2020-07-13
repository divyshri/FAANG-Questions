#include <bits/stdc++.h>
using namespace std;

int solution(string s1, string s2)
{
    int i = 0;
    int j = 0;
    int n1 = s1.size();
    int n2 = s2.size();
    while (i < n1 or j < n2)
    {
        int num1 = 0, num2 = 0;
        while (i < n1 and s1[i] != '.')
        {
            int k = s1[i] - '0';
            num1 = num1 * 10 + k;
            i++;
        }
        while (j < n2 and s2[j] != '.')
        {
            int k = s2[j] - '0';
            num2 = num2 * 10 + k;
            j++;
        }
        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;
        else
        {
            i++;
            j++;
        }
    }
    return 0;
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << solution(s1, s2) << endl;
}