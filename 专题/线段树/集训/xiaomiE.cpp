#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define eb emplace_back
using namespace std;
const int maxn=2e5+10;
const int INF=1e9;
int n,m,a[maxn];
vector<int>pos[maxn];
struct SegmentTree{//val[i]当前最右端点 ans[i]表示
	int val[maxn<<2],ans[maxn<<2],tag[maxn<<2];
	void build(int p,int l,int r){
		val[p]=tag[p]=0;
		ans[p]=INF;
		if(l==r)return;
		int mid=l+r>>1;
		build(lson);
		build(rson);
	}
	int query(int p,int l,int r,int L,int R,int rpos){
		if(val[p]>=rpos)return -1;
		if(l==r)return l;
		int mid=l+r>>1;
		if(tag[p])pushDown(p,l,r);
		if(R>mid){
			int fi=query(rson,L,R,rpos);
			if(fi!=-1)return fi;
		}
		if(L<=mid)
			return query(lson,L,R,rpos);
		return -1;
	}
	void pushDown(int p,int l,int r){
		int mid=l+r>>1;
		val[ls]=val[rs]=tag[p];
		ans[ls]=tag[p]-mid+1;
		ans[rs]=tag[p]-r+1;
		tag[ls]=tag[rs]=tag[p];
		tag[p]=0;
	}
	void pushUp(int p){
		val[p]=min(val[ls],val[rs]);
		ans[p]=min(ans[ls],ans[rs]);
	}
	void update(int p,int l,int r,int L,int R,int psVal){
		if(L<=l&&r<=R){
			val[p]=psVal;
			ans[p]=psVal-r+1;
			tag[p]=psVal;
			return;
		}
		int mid=l+r>>1;
		if(tag[p])
			pushDown(p,l,r);
		if(L<=mid)update(lson,L,R,psVal);
		if(R>mid)update(rson,L,R,psVal);
		pushUp(p);
	}
}tr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],pos[a[i]].eb(i);
	tr.build(1,1,n);
	for(int i=1;i<=m;++i){
		int now=0;
		for(auto&ps:pos[i]){
			int mxR=tr.query(1,1,n,now+1,ps,ps);
			if(mxR!=-1)
				tr.update(1,1,n,now+1,mxR,ps);
			now=ps;
		}
		if(now<n)
			tr.update(1,1,n,now+1,n,INF);
		cout<<tr.ans[1]<<" ";
	}
	return 0;
}