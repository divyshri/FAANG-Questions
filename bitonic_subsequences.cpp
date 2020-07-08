#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &ar){
	int n = ar.size();
	int left[n];
	int right[n];
	left[0] = 1;
	for(int i=1;i<n;i++){
		left[i] = 1;
		for(int j=0;j<i;j++)
			if(ar[j] < ar[i])
				left[i] = max(left[j]+1,left[i]);
	}
			
	right[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		right[i] = 1;
		for(int j=i+1;j<n;j++)
			if(ar[i] > ar[j])
				right[i] = max(right[j]+1,right[i]);
	
	}
	int ans=0;
	for(int i=0;i<n;i++){
		//cout<<"left = "<<left[i]<<"     right = "<<right[i]<<endl;	

		ans = max(ans,left[i]+right[i]-1);
	}
	return ans;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,temp;
		cin>>n;
		vector<int> ar;
		for(int i=0;i<n;i++){
			cin>>temp;
			ar.push_back(temp);
		}
		cout<<solution(ar)<<endl;
	}
}