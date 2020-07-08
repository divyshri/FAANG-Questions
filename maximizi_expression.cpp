#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> a,vector<int> b){
	int a2 = INT_MAX;
	int a1 = INT_MIN;
	int b2 = INT_MAX;
	int b1 = INT_MIN;
	int c2 = INT_MAX;
	int c1 = INT_MIN;
	int d2 = INT_MAX;
	int d1 = INT_MIN;
	for(int i=0;i<a.size();i++){
		if(a1 < a[i]+b[i]+i)			a1 = a[i]+b[i]+i;
		if(a2 > a[i]+b[i]+i)			a2 = a[i]+b[i]+i;
        if(b1 < b[i]-a[i]+i)			b1 = b[i]-a[i]+i;
		if(b2 > b[i]-a[i]+i)			b2 = b[i]-a[i]+i;
		if(c1 < b[i]+a[i]-i)			c1 = b[i]+a[i]-i;
		if(c2 > b[i]+a[i]-i)			c2 = b[i]+a[i]-i;
		if(d1 < b[i]-a[i]-i)			d1 = b[i]-a[i]-i;
		if(d2 > b[i]-a[i]-i)			d2 = b[i]-a[i]-i;
	}
	int ans = max(a1-a2,max(b1-b2,max(c1-c2,d1-d2)));
	return ans;

}

int main(){
	int n,temp;
	cin>>n;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		b.push_back(temp);
	}
	cout<<solution(a,b)<<endl;

}