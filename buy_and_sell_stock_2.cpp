#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,temp;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	int ans =0;
	for(int i=1;i<ar.size();i++){
		if(ar[i] - ar[i-1] > 0)
			ans += (ar[i] - ar[i-1]);
	}
	cout<<ans<<endl;

}