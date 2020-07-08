#include<bits/stdc++.h>
using namespace std;

bool solution(vector<vector<int>> &ar){

	for(int i=1;i<ar.size();i++){
		if(ar[i][0] < ar[i-1][1])
			return false;
	}
	return true;

}

int main(){
	int n,a,b;
	cin>>n;
	vector<vector<int>> ar;

	for(int i=0;i<n;i++){
		cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);

		ar.push_back(temp);
	}
	sort(ar.begin(),ar.end());
	/*for(auto val:ar)
		cout<<val.first<<" "<<val.second<<endl;*/
	if(solution(ar))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

}