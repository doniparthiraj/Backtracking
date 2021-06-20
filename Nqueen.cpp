#include<iostream.h>
#
using namespace std;
bool issafe(int row,int col,vector<vector<int>>&pos)
{
	for(int i=0;i<col;i++)
	if(pos[row][i])
	return false;
	for(int i=row,j=col;(i>=0 && col>=0);i--,j--)
	if(pos[i][j])
	return false;
	for(int i=row,j=col;(j>=0 && i<n);i++,j--)
	if(pos[i][j])
	return false;
	return true;
}
bool rec(int col,int n,vector<vector<int>>&pos)
{
	if(col==n)
	return true;
	for(int i=0;i<n;i++)
	{
		if(issafe(i,col,pos))
		{
			 pos[i][col]=1;
			if(rec(col+1,n,pos))
			return true;
			pos[i][col]=0; //important step
		}
	}
}
int main()
{
	 int n;
	 cin>>n;
	 vector<vector<int>>pos(n,vector<int>(n));+
	 if(!rec(0,n,pos))
	 cout<<"Not Possible";
	 else
	 {
	 	for(int i=0;i<n;i++)
	 	{
	 		for(int j=0;j<n;j++)
	 		cout<<pos[i][j]<<" ";
	 		cout<<"\n";
		 }
	 }
}
