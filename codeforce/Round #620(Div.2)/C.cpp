#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll a[1000],b[1000],c[1000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		}
		a[0]=0;
		int flag=1;
		ll l=m,r=m;
		for(int i=1;i<=n;++i)
		{
			l=l-(a[i]-a[i-1]),r=r+(a[i]-a[i-1]);
			if(l>c[i]||r<b[i]){flag=0;break;}
			else if(l<=b[i]&&r>=c[i])l=b[i],r=c[i];
			else if(l>b[i]&&r<c[i])continue;
			else if(b[i]<=r&&c[i]>=r)l=b[i];
			else if(c[i]>=l&&b[i]<=l)r=c[i];
		}
		if(!flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
} 
