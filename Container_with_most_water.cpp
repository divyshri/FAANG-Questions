#include <bits/stdc++.h>
using namespace std;
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
	int left = 0;
	int right = n - 1;
	int ans = INT_MIN;
	while (left < right)
	{
		ans = max(ans, min(ar[left], ar[right]) * (right - left));
		(ar[left] < ar[right]) ? left++ : right--;
	}
	cout << ans << endl;
}