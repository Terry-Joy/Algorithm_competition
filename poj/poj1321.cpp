#include<iostream>
using namespace std;
char chess[10][10];
int n,k,num=0,sum=0,vis[10];
void dfs(int x)
{
	if(sum==k)
	{
		num++;
		return;
	}
	if(x>=n)
	return;
	for(int j=0;j<n;++j)
	{
		if(!vis[j]&&chess[x][j]=='#')
		{
			sum++;
			vis[j]=1;
			dfs(x+1);
	 		vis[j]=0;
			--sum;
		}
	}
	dfs(x+1);
}
int main()
{
	
	while(cin>>n>>k)
	{
		if(n==-1&&k==-1)
		break;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cin>>chess[i][j];
		getchar();
	}
	dfs(0);
	cout<<num<<"\n";
	num=0;
	sum=0;
	}
	return 0;
} 
