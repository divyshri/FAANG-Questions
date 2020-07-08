#include<bits/stdc++.h>
using namespace std;

void solution(vector<int> &ar){
	int indx=0;
	for(int i=0;i<n;i++){
		if(ar[i]!=0){
			swap(ar[indx],ar[i]);
			indx++;
		}
	}
}

int main(){
	int n,temp;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	solution(ar);
	for(auto val:ar)
		cout<<val<<" ";
}