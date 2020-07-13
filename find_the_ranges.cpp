#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int i=0;
    int n = nums.size();
    while(i<n){
        int start = nums[i];
        string temp = to_string(nums[i]);            
        while(i+1<n and nums[i+1] == nums[i]+1)
            i++;
        if(nums[i] != start){
            temp += "->"+to_string(nums[i]);
        }
        
        res.push_back(temp);
        i++;
    }
    return res;
}
int main(){
	int n,temp;
	cin>>n;


	mmnm3m33 for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	vector<string> range = summaryRanges(ar);
	for(auto val:range)
		cout<<val<<" ";

}