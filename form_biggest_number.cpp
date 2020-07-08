#include<bits/stdc++.h>
using namespace std;

bool cmp(const int &a,const int &b){
	string x = to_string(a);
	string y = to_string(b);
	return x+y > x+y;
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
		sort(ar.begin(),ar.end(),cmp);
		for(int i=ar.size()-1;i>=0;i--){
			cout<<ar[i]<<" ";
		}

	}
}