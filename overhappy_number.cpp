#include<bits/stdc++.h>
using namespace std;

int sqaureSum(int n){
	int sum=0;
	while(n){
		int t = n%10;
		sum += t*t;
		n/=10;
	}
	return sum;

}

int solution(int n){
	set<int> st;
	while(1){
		n = sqaureSum(n);
		if(n==1)
			return true;
		if(st.find(n)!=st.end())
			return false;
		st.insert(n);
	}
}

int main(){
	int n;
	cin>>n;
	if(solution(n))
		cout<<"true";
	else
		cout<<"false";


}