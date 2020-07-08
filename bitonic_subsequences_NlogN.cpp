#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &ar){
	int ans = 0;
	vector<int> res(ar.size(),0);
	for(auto val:ar){
		int low = 0;
		int high = ans;
		while(low<high){
			int mid = (low+high)/2;
			if(res[mid] < val)
				low = mid+1;
			else
				high = mid;
		}
		res[low] = val;
		if(low == ans)
			ans++;
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