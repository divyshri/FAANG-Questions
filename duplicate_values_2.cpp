#include<bits/stdc++.h>
using namespace std;

bool checkDuplicate(vector<int> ar,int k){
	unordered_map<int,vector<int>> mp;
	for(int i=0;i<ar.size();i++){
		if(mp.find(ar[i])!=mp.end()){
			for(auto val:mp[ar[i]]){
				if(abs(i - val) <= k)
					return true;
			}
		}
		mp[ar[i]].push_back(i);
	}
	return false;

}

int main(){
	int n,temp;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	int k;
	cin>>k;

	if(checkDuplicate(ar,k))
		cout<<"true";
	else
		cout<<"false";



}