#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> ar)
{
	int b_indx = -1;
	int s_indx = -1;
	bool check = true;
	int i = 0;
	while (i < ar.size())
	{
		if (b_indx == -1)
		{
			b_indx = i;
			while (i < ar.size() and ar[b_indx] > ar[i + 1])
			{
				b_indx = i + 1;
				i++;
			}
		}
		else if (s_indx == -1)
		{
			s_indx = i;
			while (i < ar.size() - 1 and ar[s_indx] < ar[i + 1])
			{
				s_indx = i + 1;
				i++;
			}
		}
		if (b_indx != -1 and s_indx != -1)
		{
			cout << "(" << b_indx << " " << s_indx << ") ";
			check = false;
			b_indx = s_indx = -1;
		}
		i++;
	}
	if (check)
		cout << "No Profit";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
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
		cout << endl;
	}
}