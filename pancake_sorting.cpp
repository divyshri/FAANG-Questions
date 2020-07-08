#include<bits/stdc++.h>
using namespace std;

int find(vector<int> ar,int x){
	for(int i=0;i<ar.size();i++)
		if(ar[i] == x)
			return i;
	return -1;
}

void flip(vector<int> &ar,int n){

	for(int i=0;i<n/2;i++){
		swap(ar[i],ar[n-i-1]);
	}

}

vector<int> pancake(vector<int> ar){
	vector<int> res;
	int n = ar.size();
	while(n>0){
		int idx = find(ar,n);
		if(idx != n-1){
			flip(ar,idx+1);
			flip(ar,n);
			res.push_back(idx+1);
			res.push_back(n);
		}
		n--;
	}
	return res;
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
		vector<int> res = pancake(ar);
		for(auto val:res)
			cout<<val<<" ";
		cout<<endl;

	}

}