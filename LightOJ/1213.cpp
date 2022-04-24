#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
int n,k,mod;
ll mypow(ll a,ll b,ll c){
 	ll ans=1%c;
 	while(b){
 		if(b&1)ans=ans*a%c;
 		a=a*a%c;b>>=1;
 }	
 return ans;
} 
//64位整数乘法 (a*b)%p 10^18
#define ll long long   //类似快速幂 把b用二进制表示 
ll mul(ll a,ll b,ll p){
	ll ans=0;
	while(b){
		if(b&1)ans=(ans+a)%p;
		a=a*2%p;b>>=1;
	}
	return ans;
} 
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d%d",&n,&k,&mod);
		ll sum=0;
		int a;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("Case %d: %lld\n",i,(mul(sum,k,mod)*mypow(n,k-1,mod))%mod);
	} 
	return 0;
} 
