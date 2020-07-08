#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>> board)
{
	map<int,map<int,bool>> Row;
	map<int,map<int,bool>> Col;
	map<int,map<int,bool>> Box;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(board[i][j] != '.'){
				int num = board[i][j] - '0';
				int b= (i/3)*3 + j/3;
				if(Row[i][num] == true or Col[j][num] == true or Box[b][num] == true)
					return false;
				else{
					Row[i][num] = 1;
					Col[j][num] = 1;
					Box[b][num] = 1;
				}	
			}
			
		}
	}
	return true;


}
int main(){
	vector<vector<char>> ar;
	char matrix[9][9];
	for(int i=0;i<9;i++)
	{
		vector<char> temp; 
		for(int j=0;j<9;j++)
		{
			char ch; cin>>ch;
			temp.push_back(ch);
		}
		ar.push_back(temp);
	}
	isValidSudoku(ar)?cout<<"true":cout<<"false";

}