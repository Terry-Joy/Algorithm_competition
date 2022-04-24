#include<cstdio>
#include<iostream> 
using namespace std;
int vis[4][20],c[50],n,ans;
void search(int x)
{
	if(x==n+1)
	{
		ans++;
		if(ans>3)
		return;
		else
		{ 
		for(int i=1;i<n;++i)
		cout<<c[i]<<" ";
		cout<<c[n]<<"\n";
		} 
	}
	else 
	{
		for(int i=1;i<=n;++i)
		if(!vis[0][i]&&!vis[1][x+i]&&!vis[2][x-i+n])
		{ 
			c[x]=i;
			vis[0][i]=vis[1][x+i]=vis[2][x-i+n]=1;
			search(x+1);
			vis[0][i]=vis[1][x+i]=vis[2][x-i+n]=0;
		} 
	}
} 
int main()
{
	cin>>n;
	search(1);
	cout<<ans;
	return 0;
}
