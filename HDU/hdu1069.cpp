#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int l,w,h;
}a[200];
int z1,z2,z3,dp[200];
bool cmp(node x,node y)
{
	if(x.l==y.l)return x.w<y.w;
	return x.l<y.l;
}
int main()
{
	int n,cas=1; 
	while(~scanf("%d",&n)&&n)
	{
		int len=0;
		while(n--)
		{
			scanf("%d%d%d",&z1,&z2,&z3);
			a[len].l=z1,a[len].w=z2,a[len++].h=z3;
			a[len].l=z2,a[len].w=z1,a[len++].h=z3;
			a[len].l=z1,a[len].w=z3,a[len++].h=z2;
			a[len].l=z2,a[len].w=z3,a[len++].h=z1;
			a[len].l=z3,a[len].w=z1,a[len++].h=z2;
			a[len].l=z3,a[len].w=z2,a[len++].h=z1;
		}
		sort(a,a+len,cmp);
		dp[0]=a[0].h;				//dp[i]表示第i个作为序列结尾的最大值 
		int maxh;
		for(int i=1;i<len;++i)
		{
			maxh=0;
			for(int j=0;j<i;++j)
			{
				if(a[j].l<a[i].l&&a[j].w<a[i].w)
				maxh=max(maxh,dp[j]);
			}
			dp[i]=maxh+a[i].h;
		}
		int ans=0;
		for(int i=0;i<len;++i)
			ans=max(ans,dp[i]);
		printf("Case %d: maximum height = %d\n", cas ++, ans);
	}
	return 0;
}
