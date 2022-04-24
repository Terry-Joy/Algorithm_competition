#include<iostream>
using namespace std;
int n,k;
char a[10][10];bool b[10][10];
void dfs(int x,int y,int z)
{	
	int ans=0;
	if(z==k+1)return;	
	if(x>=n||y>=n)return;
	if(a[x][y]=='%')dfs(x+1,y,z);
	dfs(x,y+1,z);
	if(b[x][y])return;
	if(!b[x][y]&&a[x][y]=='.')
	{
		dfs(x+1,y,z);
		dfs(x,y+1,z);
		b[x][y]=1;
		ans++;
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	
	while(cin>>n>>k&&(n!=-1||k!=-1))
	{	
		
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin>>a[i]>>a[j];
			dfs(0,0,0);			
	}
	return 0;
}
