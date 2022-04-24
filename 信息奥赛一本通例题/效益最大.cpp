#include<iostream>
using namespace std;
int max1=0;
int is_exit[6],g[6],f[6];
int data1[6][6]={{0,0,0,0,0,0},{0,13,11,10,4,7},{0,13,10,10,8,5},{0,5,9,7,7,4},{0,15,12,10,11,5},{0,10,11,8,8,4}};
int dfs(int x,int y)
{
	if(x==6)
	{
		if(y>max1)
		{
			max1=y;
			for(int i=1;i<=5;++i)
			g[i]=f[i];	
		}
	}
	else for(int i=1;i<=5;++i)
		if(!is_exit[i])
		{	
			f[x]=i;
			is_exit[i]=1;
			y+=data1[x][i];
			dfs(x+1,y);
			is_exit[x]=0;
			y-=data1[x][i];		
		}	
}
int main()
{
	dfs(1,0);
	for(int i=1;i<=5;++i)
	cout<<g[i]<<" ";
	cout<<endl;
	cout<<max1;
} 
