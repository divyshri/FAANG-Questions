#include<bits/stdc++.h>
using namespace std;

int main(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;

	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;

	if((x2<=a1 or y1>=b2 or x1>=a2 or y2<=b1))
		cout<<"0"<<endl;
	else
		cout<<"1"<<endl;
}