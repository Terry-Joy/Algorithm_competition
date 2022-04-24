#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e5;
int n,rec[maxn],dt[maxn],w[maxn],wid;
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		long long ans=0;
		memset(dt,0,sizeof(dt));
		memset(rec,0,sizeof(rec));
		for(int i=1;i<=n;++i)
		scanf("%d",&rec[i]);
		int p=dt[n+1]=0;
		for(int i=1;i<=n+1;++i)
		{
			if(rec[i]>dt[p])
			{
				dt[++p]=rec[i];
				w[p]=1;
			}
			else
			{
				wid=0;
				while(dt[p]>rec[i])
				{
					wid+=w[p];
					ans=max(ans,(long long)wid*dt[p]);
					p--;
				}
				dt[++p]=rec[i],w[p]=wid+1;
			}
			
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
