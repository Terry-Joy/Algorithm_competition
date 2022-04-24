#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e4+100;
const int max1=0x7f;
int t,dp[maxn],e,f,w,n,wi[600],vi[600];
int main()
{
	scanf("%d",&t);
	while(t--)
	{ 
		scanf("%d%d",&e,&f);
		w=f-e;
		memset(dp,0x7f,sizeof(dp));
		dp[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d",&vi[i],&wi[i]);
		for(int i=1;i<=n;++i)
			for(int j=wi[i];j<=w;++j)
				dp[j]=min(dp[j],dp[j-wi[i]]+vi[i]);
		if(dp[w]==max1||w==0)
        {
            printf("This is impossible.\n");
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
        }
	} 
	return 0;
}
