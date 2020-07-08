#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> &ar){
	if(ar.size() == 0)
		return "";
	string res = ar[0];
	for(int i=1;i<ar.size();i++){
		string temp;
		for(int j=0;j<min(res.size(),ar[i].size());j++){
			if(ar[i][j] == res[j])
				temp+=res[j];
			else
				break;
		}
		res = temp;
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	string temp;
	vector<string> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	cout<<solution(ar)<<endl;

}