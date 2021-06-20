#include<bits/stdc++.h>
using namespace std;
bool issafe(int i,int j,vector<vector<int>>&maze)
{
	int n=maze.size();
	if(i<n && j<n && maze[i][j]==1)
	return 1;
	return 0;
}
bool solverec(vector<vector<int>>&maze,int i,int j,int n,vector<vector<int>>&sol)
{
	if(i==n-1 && j==n-1)
	{
		sol[i][j]=1;
		if(maze[i][j]==1)
		return true;
		else
		return false;
	}
	if(issafe(i,j,maze))
	{
		sol[i][j]=1;
		if(solverec(maze,i+1,j,n,sol))
		return true;
		else if(solverec(maze,i,j+1,n,sol))
		return true;
		sol[i][j]=0;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>maze(n,vector<int>(n));
	vector<vector<int>>sol(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>maze[i][j];
	if(solverec(maze,0,0,n,sol))
	{
		cout<<"possible Path\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<sol[i][j]<<" ";
			cout<<"\n";
		}
	}
	else
	cout<<"Not Possible";
}