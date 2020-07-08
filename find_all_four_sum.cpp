#include<bits/stdc++.h>
using namespace std;

void solution(vector<int> &ar,int k){
	unordered_map<int,pair<int,int>> mp;
	int n = ar.size();
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			mp[ar[i]+ar[j]].insert(make_pair(i,j));

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int sum = ar[i] + ar[j];
			if(mp.find(k-sum) != mp.end()){
				pair<int,int> temp = mp[k-sum];
				if(temp.first != i and temp.second != i 
					and temp.first != j and temp.second != j){
					cout<<ar[i]<<" "<<ar[j]<<" "<<ar[temp.first]<<" "<<ar[temp.second]<<" $";
				}

			}
		}
	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,temp,k;
		cin>>n>>k;
		vector<int> ar;
		for(int i=0;i<n;i++){
			cin>>temp;
			ar.push_back(temp);
		}
		solution(ar,k);
	}
}