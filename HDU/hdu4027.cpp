#include<iostream>
#include<cstdio>
#include<cmath> 
#define LL long long
using namespace std;
const int maxn=1e5+5; 
int n,m;
struct SegmentTree
{
	int l,r;LL sum;
}tr[4*maxn];
void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r;
	if(l==r){scanf("%d",&tr[p].sum);return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void update(int p,int l,int r,int ln,int rn)
{
	if(l<=ln&&rn<=r&&tr[p].sum==rn-ln+1)//¼ôÖ¦µ±Çø¼ä¸²¸Ç 
	return;
	if(ln==rn){tr[p].sum=sqrt(tr[p].sum);return;}
	int mid=ln+rn>>1;
	if(l<=mid)update(p<<1,l,r,ln,mid);
	if(r>mid)update(p<<1|1,l,r,mid+1,rn);
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
LL query(int p,int l,int r,int ln,int rn)
{
	if(l<=ln&&rn<=r)return tr[p].sum;
	int mid=ln+rn>>1;
	LL ans=0;
	if(l<=mid)ans+=query(p<<1,l,r,ln,mid);
	if(r>mid)ans+=query(p<<1|1,l,r,mid+1,rn);
	return ans;
}
int main()
{
	int t=1;
	while(scanf("%d",&n)!=EOF)
	{
		build(1,1,n);
		scanf("%d",&m);
		printf("Case #%d:\n",t++);
		for(int i=1;i<=m;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(y>z)swap(y,z);
			if(x==0)update(1,y,z,1,n);
			else printf("%lld\n",query(1,y,z,1,n));
		}
		putchar('\n');
	}
	return 0;
} 
