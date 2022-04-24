#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int t,n,a[maxn],cnt1,cnt2;
ll l1[maxn],l2[maxn],r[maxn],r2[maxn];
int main()
{
    scanf("%d",&t);
	while (t--)
	{
        scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]); 
		for (int i=1;i<=n;i++)
			if (a[i]<0) r[++cnt1]=a[i],r2[cnt1]=i;
				else if (a[i]>0) l1[++cnt2]=a[i],l2[cnt2]=i;
		int lss=1,rss=cnt2;
		ll ans=0;
		for (int i=1;i<=cnt1;i++)
		{
			while (r[i]<0)
			{
				while (l2[lss]<r2[i] && r[i]<0)
				{
					int t=min(l1[lss],abs(r[i]));
					l1[lss]-=t;
					r[i]+=t;
					if (l1[lss]==0) lss++;
				}
				if (r[i]==0) break;
				int t=min(l1[rss],abs(r[i]));
				ans+=(l2[rss]<r2[i] ? 0 : t);
				l1[rss]-=t;
				r[i]+=t;
				if (l1[rss]==0) rss--;
			}
		}
        printf("%lld\n",ans);
        cnt2=cnt1=0;
		for (int i=1;i<=cnt1;i++) r2[i]=0;
		for (int i=1;i<=cnt2;i++) l2[i]=0;
	}
	return 0;
}

