#include<bits/stdc++.h>
using namespace std;
bool issafe(int i,int j,int num,int n,vector<vector<int>>&grid)
{
	for(int k=0;k<n;k++)
	{
		if(grid[i][k]==num || grid[k][j]==num)
		return 0;
	}
	int s=sqrt(n);
	int rs=i-i%s;
	int cs=j-j%s;
	for(int i=0;i<s;i++)
	{
		for(int j=0;j<s;j++)
		if(grid[i+rs][j+cs]==num)
		return 0;
	}
	return 1;
}
bool sudoku(vector<vector<int>>&grid,int i=0,int j=0)
{
	int n=grid.size();
	if(i==n-1 && j==n)
	return 1;
	if(j==n)
	{
		i++;
		j=0;
	}
	if(grid[i][j]>0)
	return sudoku(grid,i,j+1);
	for(int num=1;num<=n;num++)
	{
		if(issafe(i,j,num,n,grid))
		{
			grid[i][j]=num;
			if(sudoku(grid))
			return true;
			grid[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>grid(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>grid[i][j];
	if(sudoku(grid))
	{
		cout<<"Possible Solution\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<grid[i][j]<<" ";
			cout<<"\n";
		}
	}
	else
	cout<<"NotPossible";
}