#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,temp;
		cin>>n;
		map<int,map<int,int>> mp;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>temp;
				mp[i][temp]++;
			}
		}
        int ans = INT_MIN;
		for(auto val:mp){
			map<int,int> temp = val.second;
			for(auto x:temp){
                if(x.first == 0)
                    ans = max(ans,x.second);
                //cout<<val.first<<"  -> "<<x.first<<" "<<x.second<<endl;
            }
		}
        cout<<ans<<endl;
	}
}