#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n/2;i++){
		cout<<i<<" "<<-1*i;
	}
	if(n%2 !=0)
		cout<<"0";
}