#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &ar){
	int final_sum=INT_MIN;
	int cur_sum=0;
	for(auto val:ar){
		cur_sum +=val;
		if(cur_sum < 0)
			cur_sum =0;
		final_sum = max(final_sum,cur_sum);
	}
	return final_sum;

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