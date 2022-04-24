#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=5e5+5;
const ll INF=1e18;
int n,a[maxn],m;
struct SegmentTree{//数域划分 最大 最小 其他值
	ll mx[maxn<<2],mx2[maxn<<2],mxc[maxn<<2];//最大 次大 数量
	ll mn[maxn<<2],mn2[maxn<<2],mnc[maxn<<2];
	ll aMx[maxn<<2],aMn[maxn<<2],aTag[maxn<<2];//对应数域加法标记
	ll sum[maxn<<2];
	int len[maxn<<2];
	void pushUp(int p){
		sum[p]=sum[ls]+sum[rs];	
		mx[p]=max(mx[ls],mx[rs]);
		mn[p]=min(mn[ls],mn[rs]);
		if(mx[ls]==mx[rs]){
			mx2[p]=max(mx2[ls],mx2[rs]);
			mxc[p]=mxc[ls]+mxc[rs];
		}else if(mx[ls]>mx[rs]){
			mx2[p]=max(mx2[ls],mx[rs]);
			mxc[p]=mxc[ls];
		}else{
			mx2[p]=max(mx[ls],mx2[rs]);
			mxc[p]=mxc[rs];
		}
		if(mn[ls]==mn[rs]){
			mn2[p]=min(mn2[ls],mn2[rs]); 
			mnc[p]=mnc[ls]+mnc[rs];
		}else if(mn[ls]<mn[rs]){
			mn2[p]=min(mn2[ls],mn[rs]);
			mnc[p]=mnc[ls];
		}else{
			mn2[p]=min(mn[ls],mn2[rs]);
			mnc[p]=mnc[rs];
		}
	}
	void build(int p,int l,int r){
		aMx[p]=aMx[p]=aTag[p]=0;
		len[p]=r-l+1;
		if(l==r){
			mx[p]=mn[p]=sum[p]=a[l];
			mxc[p]=mnc[p]=1;
			mx2[p]=-INF;
			mn2[p]=INF;
			return;
		}
		int mid=l+r>>1;
		build(lson);
		build(rson);
		pushUp(p);
	}
	void pushADD(int p,ll amx,ll amn,ll atag){//多值域加法标记下放
		if(mx[p]==mn[p]){//特判只有一个值
			if(amx==atag)amx=amn;//无最大
			else amn=amx;//无最小
			sum[p]+=amx*mxc[p];			
		}
		else sum[p]+=amx*mxc[p]+amn*mnc[p]+atag*(len[p]-mxc[p]-mnc[p]);
		//两个值时特判 次大等于最小用最小 否则其他
		if(mx2[p]==mn[p])mx2[p]+=amn;
		else if(mx2[p]!=-INF)mx2[p]+=atag;
		
		if(mn2[p]==mx[p])mn2[p]+=amx;
		else if(mn2[p]!=INF)mn2[p]+=atag;
		mx[p]+=amx;mn[p]+=amn;
		aMx[p]+=amx;aMn[p]+=amn;aTag[p]+=atag;
	}
	void pushDown(int p){
		ll Mx=max(mx[ls],mx[rs]),Mn=min(mn[ls],mn[rs]);
		pushADD(ls,(mx[ls]==Mx?aMx[p]:aTag[p]),(mn[ls]==Mn?aMn[p]:aTag[p]),aTag[p]);
		pushADD(rs,(mx[rs]==Mx?aMx[p]:aTag[p]),(mn[rs]==Mn?aMn[p]:aTag[p]),aTag[p]);
		aMx[p]=aMn[p]=aTag[p]=0;
	}
	void ADD(int p,int l,int r,int L,int R,ll val){
		if(L<=l&&r<=R) return pushADD(p,val,val,val);
		pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)ADD(lson,L,R,val);
		if(R>mid)ADD(rson,L,R,val);
		pushUp(p);
	}
	void MAX(int p,int l,int r,int L,int R,ll val){
		if(mn[p]>=val)return;
		if(L<=l&&r<=R&&mn2[p]>val)return pushADD(p,0,val-mn[p],0);
		pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)MAX(lson,L,R,val);
		if(R>mid)MAX(rson,L,R,val);
		pushUp(p);
	}
	void MIN(int p,int l,int r,int L,int R,int val){
		if(mx[p]<=val)return;
		if(L<=l&&r<=R&&mx2[p]<val)return pushADD(p,val-mx[p],0,0);
		pushDown(p);
		int mid=l+r>>1;
		if(L<=mid)MIN(lson,L,R,val);
		if(R>mid)MIN(rson,L,R,val);
		pushUp(p);
	}
	ll queryMin(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return mn[p];
		pushDown(p);
		int mid=l+r>>1;
		ll ans=INF;
		if(L<=mid)ans=min(ans,queryMin(lson,L,R));
		if(R>mid)ans=min(ans,queryMin(rson,L,R));
		return ans;
	}
	ll queryMx(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return mx[p];
		pushDown(p);
		int mid=l+r>>1;
		ll ans=-INF;
		if(L<=mid)ans=max(ans,queryMx(lson,L,R));
		if(R>mid)ans=max(ans,queryMx(rson,L,R));
		return ans;
	}
	ll querySum(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return sum[p];
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
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	cin>>m;
	tr.build(1,1,n);
	int op,l,r,x;
	for(int i=1;i<=m;++i){
		cin>>op>>l>>r;
		if(op==1){
			cin>>x;
			tr.ADD(1,1,n,l,r,x);
		}else if(op==2){
			cin>>x;
			tr.MAX(1,1,n,l,r,x);
		}else if(op==3){
			cin>>x;
			tr.MIN(1,1,n,l,r,x);
		}else if(op==4){
			cout<<tr.querySum(1,1,n,l,r)<<'\n';
		}else if(op==5){
			cout<<tr.queryMx(1,1,n,l,r)<<"\n";
		}else
			cout<<tr.queryMin(1,1,n,l,r)<<"\n";
	}
	return 0;
}