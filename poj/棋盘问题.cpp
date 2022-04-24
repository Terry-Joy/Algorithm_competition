#include<cstdio>
using namespace std;
int n,k,ans,sum;
char chess[10][10];
int a[10];
void dfs(int x)
{
	if(sum==k)
	{
	ans++;
	return;
	}
	if(x>=n)
	return;
	for(int i=0;i<n;++i)
	{
		if(!a[i]&&chess[x][i]=='#')
		{
		sum++;
		a[i]=1;
		dfs(x+1);
		a[i]=0;
		sum--;
		}
	}
	dfs(x+1);
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF) 
	{
		ans=sum=0;
		if(n==-1&&k==-1)
		break;
		for(int i=0;i<n;++i)
		scanf("%s",chess[i]);
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
