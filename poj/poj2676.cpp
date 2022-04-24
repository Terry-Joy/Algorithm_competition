#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char sudu[20][20];int sudu1[20][20];
bool row[10][10],col[10][10],grid[10][10],flag;
bool dfs(int x,int y)
{
	if(x==10)return true;
	flag=false;
	if(sudu1[x][y])
	{
		if(y==9)
		flag=dfs(x+1,1);
		else flag=dfs(x,y+1);
		if(flag)
		return true;
		else return false;
	}
	else
	{
		int k=3*((x-1)/3)+(y-1)/3+1;
		for(int i=1;i<=9;++i)
		{
		if(!row[x][i]&&!col[y][i]&&!grid[k][i])
		{
		sudu1[x][y]=i;
		row[x][i]=true;
		col[y][i]=true;
		grid[k][i]=true;
		if(y==9)
		flag=dfs(x+1,1);
		else flag=dfs(x,y+1);
		if(!flag)
		{
			sudu1[x][y]=0;
			row[x][i]=false;
		col[y][i]=false;
		grid[k][i]=false;
		} 
		else return true;
		}
		}
	}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		memset(grid,false,sizeof(grid));
		for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j)
		{
			cin>>sudu[i][j];
			sudu1[i][j]=sudu[i][j]-'0';
			if(sudu1[i][j])
			{
				int k=3*((i-1)/3)+(j-1)/3+1;
				row[i][sudu1[i][j]]=true;
				col[j][sudu1[i][j]]=true;
				grid[k][sudu1[i][j]]=true;
			}
		}
		dfs(1,1);
		for(int i=1;i<=9;++i)
		{
			for(int j=1;j<=9;++j)
			cout<<sudu1[i][j];
			putchar('\n');
		}
	}
	return 0;
}
