#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &ar,int target){

	int s = 0;
	int e = ar.size()-1;
	int n = ar.size();
	while(s<=e){
		int mid = (s+e)/2;	
		if(ar[mid] == target)
			return mid;
		if(ar[mid] > ar[n-1]){
			if(target > ar[mid] or target < ar[0])
				s = mid+1;
			else
				e = mid-1;
		}
		else {
			if(target < ar[mid] or target > ar[n-1])
				e = mid-1;
			else
				s = mid+1;
		}
	}
	return -1;

}

int main(){
	int n,temp;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	int key;
	cin>>key;
	cout<<solution(ar,key)<<endl;

}