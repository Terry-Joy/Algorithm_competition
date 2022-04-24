#include<iostream>
#include<cstring>
const int maxn=(1<<17)+10;
int n,m,x,y;
bool d;
int a[maxn];
struct SegmentTree
{
	int l,r;
	int val;
}t[4*maxn];
void Push_up(int p)
{
	if(d&1)
		t[p].val=t[p<<1].val|t[p<<1|1].val;
	else 
		t[p].val=t[p<<1].val^t[p<<1|1].val; 
	d=!d;
	return;
} 
void build(int p,int l,int r)	
{
	t[p].l=l,t[p].r=r;
	if(l==r){d=1;t[p].val=a[l];return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	Push_up(p);
}
void change(int p,int x,int v)//p是当前端点，x是要修改的端点，v是要修改的值 
{//单点修改 
	if(t[p].l==t[p].r){t[p].val=v;d=1;return;}
	int mid=(t[p].l+t[p].r)>>1;
	if(x<=mid)change(p<<1,x,v);
	else change(p<<1|1,x,v);
	Push_up(p);
}
int main()
{
	scanf("%d%d",&n,&m);
	n=1<<n;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		change(1,x,y);
		printf("%d\n",t[1].val);
	}
	return 0;	
} 
