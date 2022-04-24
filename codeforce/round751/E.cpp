#include<bits/stdc++.h>
#define fi first
#define se second
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=2e6+5;
int a[maxn],b[maxn],c[maxn*2];
pair<int,int>mp[maxn];
struct BIT{
	#define lowb(i) (i&(-i))
	int c[maxn],N;
	void init(int n){
		N=n;
		for(int i=0;i<=N;++i)c[i]=0;
	}
	void add(int x,int val){
		for(int i=x;i<=N;i+=lowb(i))
			c[i]+=val;
	}
	int ask(int x){
		int ans=0;
		for(int i=x;i;i-=lowb(i))
			ans+=c[i];
		return ans;
	}
}bit;
struct SegmentTree{
	int mn[maxn<<1],add[maxn<<1];//[i后插入的最小值]
	void pushUp(int p){
		mn[p]=min(mn[ls],mn[rs]);
	}
	void build(int p,int l,int r){
		mn[p]=add[p]=0;
		if(l==r)return;
		int mid=l+r>>1;
		build(lson);
		build(rson);
	}
	void pushDown(int p){
		mn[ls]+=add[p];
		mn[rs]+=add[p];
		add[ls]+=add[p];
		add[rs]+=add[p];
		add[p]=0;		
	}
	void update(int p,int l,int r,int L,int R,int val){
		if(L<=l&&r<=R){
			mn[p]+=val;
			add[p]+=val;
			return;
		}
		if(add[p])
			pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)update(lson,L,R,val);
		if(R>mid)update(rson,L,R,val);
		pushUp(p);
	}
}tr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i],c[i]=a[i];
		for(int i=1;i<=m;++i)
			cin>>b[i],c[i+n]=b[i];
		sort(c+1,c+1+n+m);
		int cnt=unique(c+1,c+1+n+m)-(c+1);
		for(int i=1;i<=n;++i)
			a[i]=lower_bound(c+1,c+1+cnt,a[i])-c;
		for(int i=1;i<=m;++i)
			b[i]=lower_bound(c+1,c+1+cnt,b[i])-c;
		for(int i=1;i<=n;++i)
			mp[i].fi=a[i],mp[i].se=i;
		sort(mp+1,mp+1+n);
		sort(b+1,b+1+m);
		bit.init(n+m);//注意离散化后范围！
		tr.build(1,0,n);
		ll ans=0;
		for(int i=n;i;--i){
			ans+=bit.ask(a[i]-1);
			bit.add(a[i],1);
		}
		for(int i=1;i<=n;++i)//一开始全标记为最大
			tr.update(1,0,n,i,n,1);
		int now1=1,now2=1;
		for(int i=1;i<=m;++i){
			while(now1<=n&&mp[now1].fi<=b[i])//保留左边大于当前值
				tr.update(1,0,n,mp[now1].se,n,-1),now1++;
			while(now2<=n&&mp[now2].fi<b[i])//保留右边小于当前值的
				tr.update(1,0,n,0,mp[now2].se-1,1),now2++;
			ans+=tr.mn[1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}