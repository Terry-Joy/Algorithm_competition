#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=1e5+10;
ll b[maxn],a[maxn],t,n,m,x,y,z;
ll mod=998244353;
ll mypow(ll a,ll b)
{
	ll ans=1%mod;
	while(b)
	{
		if(b&1)
		ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(z==2){a[x]++;a[y+1]--;}
			else {b[x]++;b[y+1]--;}
		}
			ll min1=a[1],min2=b[1];
			for(int i=2;i<=n;++i)
			{
				a[i]+=a[i-1];
				b[i]+=b[i-1];
				min1=min(min1,a[i]);
				min2=min(min2,b[i]);
			}	
		printf("%lld\n",mypow(2,min1)*mypow(3,min2));
	}
	return 0;
} 
