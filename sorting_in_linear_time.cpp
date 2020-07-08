#include<bits/stdc++.h>
using namespace std;

void solution(vector<int> &ar){

	int a=0;
	int b=0;
	int c=ar.size()-1;
	int i=0;

	while(i<=c){
		if(ar[i] == 0){
			swap(ar[i++],ar[a++]);
		}
		else if(ar[i] == 2){
			swap(ar[c--],ar[i]);
		}
		else
			i++;

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