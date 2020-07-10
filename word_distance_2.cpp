#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> ar,string word1,string word2){
	int ans = INT_MAX;
	int w1=-1,w2=-1;
	if(word1 == word2){
		int x = -1;
		for(int i=0;i<ar.size();i++){
			if(ar[i] == word2 and x!=-1)
				x = i;
			else{
				ans = min(ans,abs(x-i));
				x = i;
			}
			
		}	
	}
	else{
		int w1=-1,w2=-1;
		for(int i=0;i<ar.size();i++){
			if(ar[i] == word1){
				w1 = i;
			}
			else if(ar[i] == word2){
				w2 = i;
			}
			if(w1!=-1 and w2!=-1){
				ans = min(ans,abs(w2-w1));
			}
		}
	}
	return ans;
	
}

int main(){
	int n;
	cin>>n;
	vector<string> ar;
	string temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		ar.push_back(temp);
	}
	string word1,word2;
	cin>>word1;
	cin>>word2;
	cout<<solution(ar,word1,word2)<<endl;

}