#include<bits/stdc++.h>
using namespace std;
int main(){

	int n,temp;
	cin>>n;
	vector<int> ar;
    vector<long long int> left,right;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
		left.push_back((i==0)?1:ar[i-1]*left[i-1]);
	}
    right.reserve(n+1);
    for(int i=ar.size()-1;i>=0;i--){
        right[i] = (i==ar.size()-1)?1:ar[i+1]*right[i+1];
    }
    for(int i=0;i<ar.size();i++)
        cout<<left[i]*right[i]<<" ";
        //cout<<left[i]<<"  "<<right[i]<<endl;
}
