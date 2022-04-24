#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=2e6+10;
int a[500000+10],n,m,k,x,y;	
struct SegmentTree
{
	int l,r;
	int sum,dat,lm,rm;
}t[maxn];
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	
	if(l==r){t[p].lm=t[p].rm=t[p].sum=t[p].dat=a[l];return;}
	int mid=l+r>>1;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
	t[p].lm=max(t[2*p].lm,t[2*p].sum+t[2*p+1].lm);
	t[p].rm=max(t[2*p+1].rm,t[2*p+1].sum+t[2*p].rm);
	t[p].dat=max(t[2*p].dat,t[2*p+1].dat,t[2*p].rm+t[p*2+1].lm);
}
void change(int p,int x,int v)//p是当前端点，x是要修改的端点，v是要修改的值 
{//单点修改 
	if(t[p].l==t[p].r){t[p].lm=t[p].rm=t[p].sum=t[p].dat=a[l];return;}
	int mid=(t[p].l+t[p].r)>>1;
	if(x<=mid)change(p*2,x,v);
	else change(p*2+1,x,v);
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
	t[p].lm=max(t[2*p].lm,t[2*p].sum+t[2*p+1].lm);
	t[p].rm=max(t[2*p+1].rm,t[2*p+1].sum+t[2*p].rm);
	t[p].dat=max(t[2*p].dat,t[2*p+1].dat,t[2*p].rm+t[p*2+1].lm);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==2)change(1,x,y);
		else {
			if(x>y)swap(x,y);
			ask()
		}
	}
}
