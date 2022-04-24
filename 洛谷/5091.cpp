#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,m,b;
inline ll read(ll m){
 	 register ll x=0,f=0;char ch=getchar();
	 while(!isdigit(ch))ch=getchar();
	 while(isdigit(ch)){
			x=x*10+ch-'0';
			if(x>=m)f=1;
		x%=m;ch=getchar();
}
return x+(f==1?m:0);
}
ll phi(ll n){
	ll ans=n;
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
ll mypow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&a,&m);
	b=read(phi(m));
	printf("%lld\n",mypow(a,b,m));
	return 0;
}


