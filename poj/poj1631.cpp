#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
const int INF=0x7f;
using namespace std;
const int maxn=4e4+100;
int n,dp[maxn],p,a[maxn];
int main()
{
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&p);
			fill(dp,dp+p+1,INF);
			for(int i=1;i<=p;++i)
				scanf("%d",&a[i]);
			dp[1]=a[1];
			int ans=1;
			for(int i=2;i<=p;++i)
			{
				if(a[i]>=dp[ans])
					dp[++ans]=a[i];
				else 
				{
					int left=1,right=ans+1;
					while(left<right)
					{
						int mid=(left+right)/2;
						if(dp[mid]<a[i])
							left=mid+1;
						else right=mid;
					}
					dp[right]=a[i];
				}
			}
			printf("%d\n",ans);
		}
	return 0;
} 
