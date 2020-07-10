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
	int k,x;
	cin>>k>>x;
	int cur_sum = 0;
	for(int i=0;i<k;i++){
		cur_sum += abs(x-ar[i]);
	}
	int ans = cur_sum;
	int pos =0;
	for(int i=1;i<=n-k;i++){
		cur_sum -= abs(x-ar[i-1]);
		cur_sum += abs(x-ar[i+k-1]);
		if(cur_sum < ans){
			pos = i;
			ans = cur_sum;
		}
	}
	for(int i=0;i<k;i++)
		cout<<ar[i+pos]<<" ";

}