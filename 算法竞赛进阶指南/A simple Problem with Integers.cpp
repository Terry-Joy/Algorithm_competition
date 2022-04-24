
#include<iostream>
#include<cstdio>
#define ll long long
const int maxn=5e5+2;
using namespace std;
struct Node
{
	int l,r;
	ll sum,temp;
}tr[4*maxn];
int n,m,a[maxn];char c[2];
void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r;
	if(l==r){tr[p].sum=a[l];return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void spread(int p)
{
	if(tr[p].temp)
	{
		tr[p<<1].sum+=(ll)(tr[p<<1].r-tr[p<<1].l+1)*tr[p].temp;
		tr[p<<1|1].sum+=(ll)(tr[p<<1|1].r-tr[p<<1|1].l+1)*tr[p].temp;
		tr[p<<1].temp+=tr[p].temp;
		tr[p<<1|1].temp+=tr[p].temp;
		tr[p].temp=0;
	}
}
void update(int p,int l,int r,int d)
{
	if(l<=tr[p].l&&tr[p].r<=r)
	{
		tr[p].sum+=(ll)(tr[p].r-tr[p].l+1)*d;
		tr[p].temp+=d;
		return;
	}
	spread(p);
	int mid=(tr[p].r+tr[p].l)>>1;
	if(l<=mid)update(p<<1,l,r,d);
	if(r>mid)update(p<<1|1,l,r,d);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
ll ask(int p,int l,int r)
{
	if(l<=tr[p].l&&tr[p].r<=r)return tr[p].sum;
	spread(p);
	int mid=(tr[p].l+tr[p].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=ask(p<<1,l,r);
	if(r>mid)ans+=ask(p<<1|1,l,r);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%s%d%d",c,&x,&y);
		if(c[0]=='C'){
		scanf("%d",&z);
		update(1,x,y,z);
		}
		else printf("%lld\n",ask(1,x,y));
	}
	return 0;
}
 
