#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
const int maxn=1e5+10;
int n,m,l,r,d,x;ll b[maxn],a[maxn],c[maxn];
char s;
void add(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
ll ask(int x)
{
	ll ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i){
	cin>>s;
	{
		if(s=='C'){
			scanf("%d%d%d",&l,&r,&d);
		b[l]+=d,add(l,d);
		b[r+1]-=d,add(r+1,-d);
		}
		else {
		scanf("%d",&x);
		printf("%lld\n",ask(x)+a[x]);	
		}
	}
	}
	return 0;
}

