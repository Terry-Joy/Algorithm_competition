#include<iostream>
#include<cstdio>
#include<cstring>
bool dp[100010];int used[100010],a[105],b[105];
using namespace std; 
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(n|m))
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=m;++j)used[j]=0;
			for(int j=a[i];j<=m;++j)
			if(!dp[j]&&dp[j-a[i]]&&used[j-a[i]]<b[i])
			{
				dp[j]=1,used[j]=used[j-a[i]]+1; 
				ans++;
			}
		}
		printf("%d\n",ans);
	} 
}
