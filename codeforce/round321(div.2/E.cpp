#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
char s[maxn];
struct SegmentTree{
	#define lson p<<1,l,mid 
	#define rson p<<1|1,mid+1,r
	#define ls p<<1
	#define rs p<<1|1
	int has[maxn<<2],base,mod;
	int add[maxn<<2],pw[maxn<<2],sum[maxn];
	void pushUp(int p,int l,int r,int mid){
		has[p]=((ll)has[ls]*pw[r-mid]%mod+has[rs])%mod;
	}
	void build(int p,int l,int r){
		has[p]=0;
		add[p]=-1;
		if(l==r){
			has[p]=s[l]-'0';
			return;
		}
		int mid=l+r>>1;
		build(lson);
		build(rson);
		pushUp(p,l,r,mid);   
	}
	void pushDown(int p,int l,int r,int mid){
		has[ls]=(ll)sum[mid-l+1]*add[p]%mod;
		has[rs]=(ll)sum[r-mid]*add[p]%mod;
		add[ls]=add[rs]=add[p];
		add[p]=-1;
	}
	void update(int p,int l,int r,int L,int R,int val){
		if(L<=l&&r<=R){
			has[p]=(ll)sum[r-l+1]*val%mod;
			add[p]=val;
			return;
		}
		int mid=l+r>>1;
		if(add[p]!=-1)
			pushDown(p,l,r,mid);
		if(L<=mid)update(lson,L,R,val);
		if(R>mid)update(rson,L,R,val);
		pushUp(p,l,r,mid);
	}
	int query(int p,int l,int r,int L,int R){
		if(L>R)return 0;
		if(L<=l&&r<=R)
			return has[p];
		int mid=l+r>>1,f=0,x1,x2,x;
		if(add[p]!=-1)
			pushDown(p,l,r,mid);
		if(L<=mid){
			x1=query(lson,L,R);
			f++;
		}
		if(R>mid){
			x2=query(rson,L,R);
			f+=2;
		}
		if(f==1){
			x=x1;
		}else if(f==2){
			x=x2;
		}else{
			x=((ll)x1*pw[min(r,R)-mid]%mod+x2)%mod;
		}
		return x;
	}
}tr[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	tr[0].base=27;tr[0].mod=1e9+7;
	tr[1].base=233;tr[1].mod=1e9+9;
	tr[0].sum[1]=tr[1].sum[1]=1;
	tr[0].pw[0]=tr[1].pw[0]=1;
	for(int j=0;j<2;++j){
		for(int i=1;i<maxn;++i)
			tr[j].pw[i]=(ll)tr[j].pw[i-1]*tr[j].base%tr[j].mod;
	}
	for(int i=2;i<maxn;++i)
		for(int j=0;j<2;++j){
			tr[j].sum[i]=(ll)tr[j].sum[i-1]*tr[j].base%tr[j].mod+1;
		}
	int n,m,k;
	cin>>n>>m>>k;
	cin>>(s+1);
	for(int j=0;j<2;++j){
		tr[j].build(1,1,n);
	}
	for(int i=1;i<=m+k;++i){
		int op,l,r,c;
		cin>>op>>l>>r>>c;
		if(op==1){
			for(int j=0;j<2;++j)
				tr[j].update(1,1,n,l,r,c);
		}else{
			if(r-l+1==c){
				cout<<"YES\n";continue;
			}
			int x[4];
			x[0]=tr[0].query(1,1,n,l+c,r),x[1]=tr[0].query(1,1,n,l,r-c);
			x[2]=tr[1].query(1,1,n,l+c,r),x[3]=tr[1].query(1,1,n,l,r-c);
			if(x[0]==x[1]&&x[2]==x[3])
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}