#include <bits/stdc++.h>
using namespace std;

bool checkString(string a, string b)
{
    string s1 = (a.length() <= b.length()) ? a : b;
    string s2 = (a.length() > b.length()) ? a : b;
    int i = 0, j = 0, count = 0;
    if (s1.length() < s2.length())
    {
        while (s1.length() and j < s2.length())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
                count++;
            }
            else
                j++;
        }
    }
    else
    {
        while (i < s1.length() and j < s2.length())
        {
            if (s1[i] == s2[j])
            {
                count++;
            }
            i++;
            j++;
        }
    }
    return (s2.length() - 1 == count) ? true : false;
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (checkString(s1, s2))
        cout << "True";
    else
        cout << "False";
}
