#include<iostream>
#include<cstdio>
#define ll long long 
const int maxn=1e5+10;
using namespace std;
int n,q;
ll b[2][maxn],a[maxn],sum[maxn];
void add(int x,int y,int z)
{
	for(;y<=n;y+=y&-y)b[x][y]+=z;
}
ll ask(int a,int x)
{
	 ll ans=0;
	 for(;x;x-=x&-x)ans+=b[a][x];
	 return ans; 
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	while(q--)
	{
		int x,y,z;char c[2];
		scanf("%s%d%d",c,&x,&y);
		if(c[0]=='C')
		{
			scanf("%d",&z);
			add(0,x,z);add(0,y+1,-z);
			add(1,x,x*z);add(1,y+1,-z*(y+1));
		}
		else 
		{
			long long ans=sum[y]+(y+1)*ask(0,y)-ask(1,y);
			ans-=sum[x-1]+x*ask(0,x-1)-ask(1,x-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
