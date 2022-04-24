#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main()
{
	int q,n,r;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&r);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int m=unique(a+1,a+n+1)-a-1;
		int ans=1;
		int t=r;
		for(int i=m-1;i>=1;--i)
		{
			if(a[i]>t)ans++;
			t+=r;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
