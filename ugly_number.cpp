#include <bits/stdc++.h>
using namespace std;

int uglyNumber(int n)
{
	set<long long> possibleSet, fixed;
	possibleSet.insert(1);
	while ((int)fixed.size() != n)
	{
		long long temp = *possibleSet.begin();
		fixed.insert(temp);
		possibleSet.erase(temp);
		possibleSet.insert(2 * temp);
		possibleSet.insert(3 * temp);
		possibleSet.insert(5 * temp);
	}
	return *fixed.rbegin();
}

int main()
{
	int n;
	cin >> n;
	cout << uglyNumber(n) << endl;
}

/*
#include<iostream>
using namespace std;
#define ll long long int
int main()
 {
	
	int t;
	cin>>t;
	ll ugly[10000];
	ugly[0]=1;
	ll i2=0,i3=0,i5=0,n2,n3,n5;
	for(int i=1;i<10000;i++){
	    n2=ugly[i2]*2;
	    n3=ugly[i3]*3;
	    n5=ugly[i5]*5;
	    ugly[i]=min(n3,min(n2,n5));
	    if(ugly[i]==n2)
	    i2++;
	    
	    if(ugly[i]==n3)
	    i3++;
	    
	    if(ugly[i]==n5)
	    i5++;
	    
	}
	
	while(t--){
	    int n;
	    cin>>n;
	    cout<<ugly[n-1]<<endl;
	}
	return 0;
}
*/