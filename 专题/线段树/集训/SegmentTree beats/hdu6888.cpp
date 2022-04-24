#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=4e5+10;
const int INF=2e9;
int t,n,X[maxn],cntx;
struct Q{
	int l,r,h;
}q[maxn];
struct SegmentTree{
	//sum维护[l,r]中[l,r-1]中a[i]和a[i+1]有且仅有一个==mn的数量
	int mn[maxn<<2],se[maxn<<2],tag[maxn<<2],sum[maxn<<2],Lv[maxn<<2],Rv[maxn<<2];
	bool is[maxn<<2];
	ll val1[maxn<<2],val2[maxn<<2];
	void build(int p,int l,int r){
		sum[p]=mn[p]=tag[p]=val1[p]=val2[p]=Lv[p]=Rv[p]=is[p]=0;
		se[p]=INF;
		if(l==r)return;
		int mid=l+r>>1;
		build(lson);
		build(rson);
	}
	void pushUp(int p){
		val2[p]=val2[ls]+val2[rs]+abs(Rv[ls]-Lv[rs]);
		Lv[p]=Lv[ls];
		Rv[p]=Rv[rs];
		mn[p]=min(mn[ls],mn[rs]);
		if(mn[ls]==mn[rs]){
			se[p]=min(se[ls],se[rs]);
			sum[p]=sum[ls]+sum[rs];
		}else if(mn[ls]<mn[rs]){
			se[p]=min(se[ls],mn[rs]);
			sum[p]=sum[ls];
		}else{
			se[p]=min(se[rs],mn[ls]);
			sum[p]=sum[rs];
		}
		if((Rv[ls]==mn[p]||Lv[rs]==mn[p])&&Rv[ls]!=Lv[rs])sum[p]++;
	}
	void add_tag(int p,int c){
		if(mn[p]>=c)return;
		val2[p]-=(ll)sum[p]*(c-mn[p]);
		if(Lv[p]==mn[p])Lv[p]=c;//左右也要更新
		if(Rv[p]==mn[p])Rv[p]=c;
		mn[p]=tag[p]=c;
	}
	void pushDown(int p){
		add_tag(ls,tag[p]);
		add_tag(rs,tag[p]);
		tag[p]=0;
	}
	void pushUp2(int p){
		val1[p]=val1[ls]+val1[rs];
	}
	void update2(int p,int l,int r,int L,int R){
		if(is[p])return;
		if(L<=l&&r<=R){
			val1[p]=X[r+1]-X[l];
			is[p]=1;
			return;
		}
		int mid=l+r>>1;
		if(L<=mid)update2(lson,L,R);
		if(R>mid)update2(rson,L,R);
		pushUp2(p);
	}
	void update1(int p,int l,int r,int L,int R,int val){
		if(mn[p]>=val)return;
		if(L<=l&&r<=R&&se[p]>val){
			add_tag(p,val);
			return;
		}
		if(tag[p])
			pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)update1(lson,L,R,val);
		if(R>mid)update1(rson,L,R,val);
		pushUp(p);
	}
}tr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cntx=0;
		for(int i=1;i<=n;++i){
			cin>>q[i].l>>q[i].r>>q[i].h;
			X[++cntx]=q[i].l;X[++cntx]=q[i].r;
		}
		sort(X+1,X+1+cntx);
		int m=unique(X+1,X+1+cntx)-(X+1);
		for(int i=1;i<=n;++i){
			q[i].l=lower_bound(X+1,X+1+m,q[i].l)-X;
			q[i].r=lower_bound(X+1,X+1+m,q[i].r)-X;
		}
		tr.build(1,0,m+1);//边界2个0
		for(int i=1;i<=n;++i){
			tr.update2(1,0,m+1,q[i].l,q[i].r-1);
			tr.update1(1,0,m+1,q[i].l,q[i].r-1,q[i].h);
			cout<<tr.val1[1]*2+tr.val2[1]<<"\n";		
		}
	}
	return 0;
}