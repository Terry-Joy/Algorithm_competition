#include<iostream>
#include<cstdio>
#define ll long long
#include<cmath>
using namespace std;
int mod=1000,n,k;
ll mypow(ll a,ll b)
{
	ll ans=1;
	while(b){
		if(b&1)
		ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return (int)ans;
}
int main()
{
	ll res1,res2,num=1;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		double x,y;
		y=modf((double)(k*log10(n)),&x);
		res1=int(pow(10,y)*100);
		res2=int(mypow(n,k));
		printf("Case %d: %d %03d\n",num++,res1,res2);
	}	
	return 0;
} 
