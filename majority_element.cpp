#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> &ar){
	int ele1=0,ele2=0,c1=0,c2=0;
	for(auto val:ar){
		if(ele1 == val)
			c1++;
		else if(ele2 == val)
			c2++;
		else if(c1 == 0){
			ele1 = val;
			c1=0;
		}
		else if(c2 == 0){
			ele2 = val;
			c2=0;
		}
		
		else{
			c1--;
			c2--;
		}
	}
	c1 =c2 = 0;
	for(auto val:ar){
		if(val == ele1)
			c1++;
		else if(val == ele2)
			c2++;
	}
	vector<int> res;
	if(c1 > floor(n/3))
		res.push_back(ele1);
	if(c2 > floor(n/3))
		res.push_back(ele2)
	return res;
}
int main(){
	int n,temp;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	vector<int> res = solution(ar);
	if(res.size()==0)
		cout<<"No Majority Elements"<<endl;
	else{
		for(auto val:res)
			cout<<val<<" ";
	}
}