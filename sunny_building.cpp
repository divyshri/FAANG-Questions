#include<bits/stdc++.h>
using namespace std;
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
		int max_till_now = ar[0];
		int count =1;
		for(int i=1;i<n;i++){
			if(ar[i]>max_till_now){
				max_till_now = ar[i];
				count++;
			}
		}
		cout<<count<<endl;
	}
}