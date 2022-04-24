#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=1e6+5;
int n,m,a[maxn];
struct SegmentTreeBeats{
	//分最大，次大,最大数量
	int mx[maxn<<2],se[maxn<<2],tag[maxn<<2],cnt[maxn<<2];
	ll sum[maxn<<2];
	void pushUp(int p){
		sum[p]=sum[ls]+sum[rs];
		mx[p]=max(mx[ls],mx[rs]);
		if(mx[ls]==mx[rs]){
			se[p]=max(se[ls],se[rs]);
			cnt[p]=cnt[ls]+cnt[rs];
		}else if(mx[ls]>mx[rs]){
			se[p]=max(se[ls],mx[rs]);
			cnt[p]=cnt[ls];
		}else{
			se[p]=max(mx[ls],se[rs]);
			cnt[p]=cnt[rs];
		}
	}
	void build(int p,int l,int r){
		tag[p]=-1;
		if(l==r){
			mx[p]=sum[p]=a[l];
			se[p]=-1;//初始化严格小于最大值
			cnt[p]=1;
			return;
		}
		int mid=l+r>>1;
		build(lson);
		build(rson);
		pushUp(p);
	}
	void add_tag(int p,int c){
		if(mx[p]<=c)return;//可能最大值不在该子区间
		sum[p]-=(ll)cnt[p]*(mx[p]-c);
		mx[p]=tag[p]=c;
	}
	void pushDown(int p){
		add_tag(ls,tag[p]);
		add_tag(rs,tag[p]);	
		tag[p]=-1;
	}
	void update(int p,int l,int r,int L,int R,int val){
		if(mx[p]<=val)return;
		if(L<=l&&r<=R&&val>se[p]){
			add_tag(p,val);
			return;
		}
		if(tag[p]!=-1)
			pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)update(lson,L,R,val);
		if(R>mid)update(rson,L,R,val);
		pushUp(p);
	}
	int queryMx(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return mx[p];
		if(tag[p]!=-1)
			pushDown(p);
		int mid=l+r>>1,ans=0;
		if(L<=mid)ans=max(ans,queryMx(lson,L,R));
		if(R>mid)ans=max(ans,queryMx(rson,L,R));
		return ans;
	}
	ll querySum(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return sum[p];
		if(tag[p]!=-1)
			pushDown(p);
		int mid=l+r>>1;
		ll ans=0;
		if(L<=mid)ans+=querySum(lson,L,R);
		if(R>mid)ans+=querySum(rson,L,R);
		return ans;
	}
}tr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		tr.build(1,1,n);
		int op,x,y,z;
		for(int i=1;i<=m;++i){
			cin>>op>>x>>y;
			if(!op){
				cin>>z;
				tr.update(1,1,n,x,y,z);
			}else if(op==1){
				cout<<tr.queryMx(1,1,n,x,y)<<"\n";
			}else 
				cout<<tr.querySum(1,1,n,x,y)<<"\n";
		}
	}
	return 0;
}
