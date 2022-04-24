#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int mod=9901;int a,b,cnt; ll ans=1;
int p[30],c[30];
ll mypow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void divide(int n)
{
	cnt=0;
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0){
			p[++cnt]=i;c[cnt]=0;
			while(n%i==0){c[cnt]++;n/=i;}
		}
	}
	if(n>1)p[++cnt]=n,c[cnt]=1;
}
int main()
{
	scanf("%d%d",&a,&b);
	divide(a);
	for(int i=1;i<=cnt;++i)
	{
		if((p[i]-1)%mod==0){
			ans=((ll)b*c[i]+1)%mod*ans%mod;
			continue;
		}
		int x=mypow(p[i],(ll)b*c[i]+1);
		x=(x-1%mod)%mod;
		int y=p[i]-1;
		y=(y,mod-2);
		ans=(ll)ans*x%mod*y%mod;
	}
	printf("%d\n",ans);
	return 0;
} 
