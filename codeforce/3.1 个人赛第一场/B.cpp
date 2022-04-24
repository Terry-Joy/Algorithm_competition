#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
ll x[200005],y[200005];

ll area(ll a1,ll a2,ll a3,ll a4)
{
	return abs((ll)a1*a2-(ll)a3*a4);
}

int main()
{
	int n;
	scanf("%d",&n);
	int cnt=n;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&x[i],&y[i]);
	} 
	x[n+1]=x[1],x[n+2]=x[2];
	y[n+1]=y[1],y[n+2]=y[2];
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		ll a1=x[i+1]-x[i];
       	ll a2=y[i+2]-y[i];
        ll a4=y[i+1]-y[i];
        ll a3=x[i+2]-x[i];
        ll k=area(a1,a2,a3,a4);
        ans=min(ans,k);

	}
	printf("%lld",ans);
	return 0;
}
 
