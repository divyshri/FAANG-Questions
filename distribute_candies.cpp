#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,temp;
	cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>temp;
		mp[temp]++;
	}
	int ans = (mp.size()<n/2)?mp.size():n/2;
	cout<<ans<<endl;

	
	return 0;
}