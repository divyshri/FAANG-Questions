#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> ar){
	int sum=0;
	int ans=0;
	map<int,int> mp;
	mp.insert(make_pair(0,-1));
	for(int i=0;i<ar.size();i++){
		if(ar[i] == 0)
			sum++;
		else
			sum--;
		if(mp.find(sum)!=mp.end())
			ans = max(ans,i-mp[sum]);
		else
			mp.insert(make_pair(sum,i));
	}
	return ans;
}

int main(){
	int n,temp;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	cout<<solution(ar)<<endl;

}