#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int maxn=200007;
int n,m,x,y,z,k;LL a[maxn],P;
struct rec
{
	int l,r;LL sum,addmark=0,mulmark=1;	
}tr[4*maxn];
void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r;
	if(r==l){tr[p].sum=a[l];return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].sum=((tr[p<<1].sum%P)+(tr[p<<1|1].sum%P))%P;
}
void pushDown(int p)
{
	if(tr[p].addmark==0&&tr[p].mulmark==1)return;
	tr[p<<1].mulmark=(tr[p<<1].mulmark*tr[p].mulmark)%P;
	tr[p<<1|1].mulmark=(tr[p<<1|1].mulmark*tr[p].mulmark)%P;
	tr[p<<1].addmark=(tr[p].mulmark*tr[p<<1].addmark+tr[p].addmark)%P;
	tr[p<<1|1].addmark=(tr[p].mulmark*tr[p<<1|1].addmark+tr[p].addmark)%P;
	tr[p<<1].sum=(tr[p].mulmark*tr[p<<1].sum+(tr[p<<1].r-tr[p<<1].l+1)*tr[p].addmark)%P;
	 tr[p<<1|1].sum=(tr[p].mulmark*tr[p<<1|1].sum+(tr[p<<1|1].r-tr[p<<1|1].l+1)*tr[p].addmark)%P;;
	tr[p].mulmark=1,tr[p].addmark=0;
}
void update2(int l,int r,int ln,int rn,int p,LL v)
{
	if(l<=ln&&rn<=r)
	{
		tr[p].sum=(tr[p].sum*v)%P;
		tr[p].mulmark*=v;
		return;
	}
	int mid=ln+rn>>1;
	pushDown(p);
	if(l<=mid)update2(l,r,ln,mid,p<<1,v);
	if(r>mid)update2(l,r,mid+1,rn,p<<1|1,v);
	tr[p].sum=(tr[p<<1].sum+tr[p<<1|1].sum)%P; 
}
void update1(int l,int r,int ln,int rn,int p,LL v)
{
	if(l<=ln&&rn<=r)
	{
		tr[p].sum=(tr[p].sum+v*(rn-ln+1))%P;
		tr[p].addmark+=v;						//加法标记 
		return;
	}
	int mid=ln+rn>>1;
	pushDown(p); 								//检查标记更新 
	if(l<=mid)update1(l,r,ln,mid,p<<1,v);
	if(r>mid)update1(l,r,mid+1,rn,p<<1|1,v);
	tr[p].sum=(tr[p<<1].sum+tr[p<<1|1].sum)%P; 
}
LL query(int L,int R,int l,int r,int p)
{
	if(L<=l&&R>=r)return tr[p].sum;
	int mid=l+r>>1;
	pushDown(p);		//只有被询问到才更新子树 
	LL ans=0;
	if(l<=mid)ans+=query(L,R,l,mid,p<<1),ans%=P;			//自下向上累加 
	if(r>mid)ans+=query(L,R,mid+1,r,p<<1|1),ans%=P;
	return ans;		
}
int main()
{
	scanf("%d%lld",&n,&P);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	build(1,1,n); 
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==3)printf("%lld\n",query(y,z,1,n,1));
		else 
		{
			scanf("%d",&k);
			if(k==1)update2(y,z,1,n,1,k);
			else update1(y,z,1,n,1,k);	
		}
	}			
	return 0;	
} 
