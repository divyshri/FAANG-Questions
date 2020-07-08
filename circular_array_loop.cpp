#include<bits/stdc++.h>
using namespace std;

int next(vector<int> ar,int i){
	return (i+ar[i]+ar.size())%ar.size();
}

int solution(vector<int> ar){
	int n = ar.size();
	
	for(int i=0;i<n;i++){
		if(ar[i] == 0)
			continue;
		int slow = i,fast=i;
		while( ar[slow]*ar[next(ar,slow)]>0 and	ar[fast]*ar[next(ar,fast)]>0 and ar[fast]*ar[next(ar,next(ar,fast))]>0){
			slow = next(ar,slow);
			fast = next(ar,next(ar,fast));

			if(slow == fast){
				if(slow == next(ar,slow))
					break;
				return true;
			}
		}
		slow = i;
		int val = ar[slow];
		while(val*ar[slow]>0){
			int temp = slow;
			slow = next(ar,slow);
			ar[temp] = 0;
		}
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
	cout<<solution(ar)<<endl;
}