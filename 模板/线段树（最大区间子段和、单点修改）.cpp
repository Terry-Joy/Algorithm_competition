#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
const int INF = 0x3fffffff;
int a[N];
struct segment_tree
{
  	int l;
  	int r;
    int dat;//区间最大连续子段和
    int lmax;//紧靠左端的最大连续和
    int rmax;//紧靠右段的最大连续和
    int sum;//区间和
}tree[N<<2];
void pushup(int rt)
{
   tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
   tree[rt].lmax = max(tree[rt<<1].lmax,tree[rt<<1].sum+tree[rt<<1|1].lmax);
   tree[rt].rmax = max(tree[rt<<1|1].rmax,tree[rt<<1|1].sum+tree[rt<<1].rmax);
   tree[rt].dat = max(max(tree[rt<<1].dat,tree[rt<<1|1].dat),tree[rt<<1].rmax+tree[rt<<1|1].lmax);//最大连续子段和 
}
void build(int rt,int l,int r)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l == r)
	{
		tree[rt].dat = tree[rt].rmax = tree[rt].lmax = tree[rt].sum = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int x,int val)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(l == r) {tree[rt].dat = tree[rt].sum = tree[rt].lmax = tree[rt].rmax = val;return;}
	int mid = (l+r)>>1;
	if(x <= mid) update(rt<<1,x,val);
	else update(rt<<1|1,x,val);
	pushup(rt);
}
segment_tree ask(int rt,int L,int R)
{
	int l = tree[rt].l;
	int r = tree[rt].r;
	if(L <= l && r <= R) return tree[rt];
	segment_tree a,b,ans;
	a.sum = a.dat = a.lmax = a.rmax = b.sum = b.dat = b.lmax = b.rmax = -INF;
    ans.sum = 0;
	int mid = (l+r)>>1;
	if(L <= mid) 			//先更新总和 
	{
		a = ask(rt<<1,L,R);
		ans.sum += a.sum;
	}
	if(R > mid)
	{
		b = ask(rt<<1|1,L,R);
		ans.sum += b.sum;
	}
	if(L > mid)				//再讨论左右最大值 
		ans.lmax = b.lmax;
	else ans.lmax = max(a.lmax,a.sum+b.lmax);
	if(R <= mid)
		ans.rmax = a.rmax;
	else ans.rmax = max(b.rmax,b.sum+a.rmax);
	ans.dat = max(max(a.dat,b.dat),a.rmax+b.lmax);		//自下向上更新 
	return ans;
}
int main ()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    build(1,1,n);
    while(m--)
    {
    	int op,x,y;
    	cin>>op>>x>>y;
    	if(op == 1)
    	{
    	   if(x > y) swap(x,y);
           cout<<ask(1,x,y).dat<<endl;
    	}
    	else
    	{
          update(1,x,y);
    	}
    }
	return 0 ;
}

