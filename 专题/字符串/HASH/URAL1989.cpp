#include<bits/stdc++.h>
#define fi first 
#define se second
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using ull=unsigned int long long;
using namespace std;
const int base=131;
const int maxn=1e5+10;
ull pw[maxn];
struct SegmentTree{
	ull has[maxn<<2],rhas[maxn<<2];
	void pushUp(int p,int l,int r,int mid){
		has[p]=has[ls]*pw[r-mid]+has[rs];
		rhas[p]=rhas[ls]+rhas[rs]*pw[mid-l+1];
	}
	void update(int p,int l,int r,int x,char val){
		if(l==r){
			has[p]=rhas[p]=val;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)update(lson,x,val);
		else update(rson,x,val);
		pushUp(p,l,r,mid);
	}
	pair<ull,ull>query(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return {has[p],rhas[p]};
		}
		int mid=l+r>>1,f=0;
		pair<ull,ull>x1,x2,x;
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
		}else if(f==3){
			x.fi=x1.fi*pw[min(r,R)-mid]+x2.fi;
			x.se=x1.se+x2.se*pw[mid-max(l,L)+1];
		}
		return x;
	}
}tr;
char s[maxn];
int main(){
	pw[0]=1;
	for(int i=1;i<maxn;++i)pw[i]=pw[i-1]*base;
	while(cin>>(s+1)){
		int n=strlen(s+1),m;
		for(int i=1;i<=n;++i)tr.update(1,1,n,i,s[i]);
		char ss[20];
		cin>>m;
		for(int i=1;i<=m;++i){
			cin>>ss;
			int l1,r1;
			if(ss[0]=='p'){
				cin>>l1>>r1;
				auto x=tr.query(1,1,n,l1,r1);
				cout<<(x.fi==x.se?"Yes\n":"No\n");
			}else{
				char c;
				cin>>l1>>c;
				tr.update(1,1,n,l1,c);
			}
		}
	}
    return 0;
}
