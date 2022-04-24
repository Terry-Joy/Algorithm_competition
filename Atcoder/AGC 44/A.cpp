#include<bits/stdc++.h>
#define gc getchar()
using namespace std;
typedef long long ll;

template<class o> void read(o&x) {
	char c=gc; x=0; int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=gc;}
	while(isdigit(c))x=x*10+c-'0',c=gc;
	x*=f;
}

int T;
ll n,a,b,c,d;
map<ll,ll> s;

ll dfs(ll n) {
	if(s.count(n)) return s[n];
	ll ans=n<1e18/d?n*d:(ll)1e18;
	ll l1=(n/2)*2,r1=((n+1)/2)*2;
	ll l2=(n/3)*3,r2=((n+2)/3)*3;
	ll l3=(n/5)*5,r3=((n+4)/5)*5;
	ans=min(ans,(n-l1)*d+dfs(l1/2)+a);
	ans=min(ans,(r1-n)*d+dfs(r1/2)+a);
	ans=min(ans,(n-l2)*d+dfs(l2/3)+b);
	ans=min(ans,(r2-n)*d+dfs(r2/3)+b);
	ans=min(ans,(n-l3)*d+dfs(l3/5)+c);
	ans=min(ans,(r3-n)*d+dfs(r3/5)+c);
	return s[n]=ans;
}

int main() {
	read(T); while(T--)
	 {
		read(n); read(a); read(b); read(c); read(d);
		s.clear(); 
		s[0]=0; s[1]=d; 
		printf("%lld\n",dfs(n));
	}
	return 0;
}
