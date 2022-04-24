#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define eb emplace_back
using namespace std;
const int maxn=1e6+5;
const int INF=2e9;
int n,q,a[maxn];
int rd(int&x){
	char c=getchar();x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct OP{
	int v,t,id;
	OP(int _v,int _t,int _id):v(_v),t(_t),id(_id){

	}
};
struct SegmentTreebeats{
	int mx[maxn<<2],se[maxn<<2],sum[maxn<<2],tag[maxn<<2];
	void pushUp(int p){
		mx[p]=max(mx[ls],mx[rs]);
		if(mx[ls]==mx[rs]){
			se[p]=max(se[ls],se[rs]);
		}else if(mx[ls]>mx[rs]){
			se[p]=max(se[ls],mx[rs]);
		}else{
			se[p]=max(mx[ls],se[rs]);
		}
	}
	void build(int p,int l,int r){
		mx[p]=INF;se[p]=-INF;sum[p]=0;
		tag[p]=-1;
		if(l==r)return;
		int mid=l+r>>1;
		build(lson);
		build(rson);
	}
	void pushDown(int p){
		add_tag(ls,tag[p],sum[p]);
		add_tag(rs,tag[p],sum[p]);
		tag[p]=-1;sum[p]=0;
	}
	void add_tag(int p,int c,int val){
		if(mx[p]<=c)return;
		mx[p]=tag[p]=c;
		sum[p]+=val;
	}
	void update(int p,int l,int r,int L,int R,int val){
		if(mx[p]<=val)return;
		if(L<=l&&r<=R&&val>se[p]){
			add_tag(p,val,1);
			return;
		}
		if(tag[p]!=-1||sum[p]!=0)
			pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)update(lson,L,R,val);
		if(R>mid)update(rson,L,R,val);
		pushUp(p);
	}
	int query(int p,int l,int r,int x){
		if(l==r)return sum[p];
		if(tag[p]!=-1||sum[p]!=0)
			pushDown(p);
		int mid=l+r>>1;
		if(x<=mid)return query(lson,x);
		else return query(rson,x);
	}
}tr;
vector<OP>res[maxn],Q[maxn];
int ans[maxn];
int main(){
	rd(n);rd(q);
	for(int i=1;i<=n;++i){
		rd(a[i]);
		res[i].eb(a[i],0,0);
	}
	int op,x,v,T=0;
	for(int i=1;i<=q;++i){
		rd(op);rd(x);
		if(op==1){
			rd(v);
			res[x].eb(v,++T,i);
		}else{
			Q[x].eb(0,++T,i);
		}
	}
	tr.build(1,0,T);
	for(int i=n;i;--i){
		int num=res[i].size(),num2=Q[i].size();
		for(int j=0;j<num-1;++j){
			tr.update(1,0,T,res[i][j].t,res[i][j+1].t-1,res[i][j].v);
		}
		tr.update(1,0,T,res[i][num-1].t,T,res[i][num-1].v);
		for(int j=0;j<num2;++j){
			ans[Q[i][j].id]=tr.query(1,0,T,Q[i][j].t);
		}
	}
	for(int i=1;i<=q;++i){
		if(ans[i])
		cout<<ans[i]<<"\n";
	}
	return 0;
}