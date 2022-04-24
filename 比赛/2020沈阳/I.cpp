#include<iostream>
#include<cstdio>
#define ll long long
#define int long long
using namespace std;

ll f(ll a, ll b, ll c, ll n) 
{
	if(!a) return b/c*(n+1);
	if(a>=c||b>=c)
	return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
	ll m=(a*n+b)/c;
	return n*m-f(c,c-b-1,a,m-1);
}

signed main( )
{
	int h,m,a;
	scanf("%lld%lld%lld",&h,&m,&a);
	if(a==h*m/2){
		cout<<h*m;return 0;
	}
	else{
		int ans1=f( h*m ,a+h*m, h-1 ,  h-3 );
		int ans2=f( h*m ,-a+h*m-1, h-1 , h-3 );
		int ans=ans1-ans2;
		ans+=(a/(h-1));
		ans+=(a/(h-1))+1;
		printf("%lld\n",ans);
	}
	// ans=ans +1 + a/(h-1) ;
	// ans=ans + a/(h-1) +1;
	// ans--;
	
	//ans=min(ans,h*m);
	
	return 0;
}
