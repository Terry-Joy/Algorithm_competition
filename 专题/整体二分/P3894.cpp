#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct Query{
	int l,r,k,id,type;
}q[maxn<<1],q1[maxn<<1],q2[maxn<<1];
int a[maxn],b[maxn],cnt,val[maxn],tot,ans[maxn],n,m;
struct BIT{
	#define lowb(i) (i&(-i))
	int c[maxn];
	void add(int x,int val){
		for(int i=x;i<=n;i+=lowb(i))
			c[i]+=val;
	}
	int ask(int x){
		int ans=0;
		for(int i=x;i;i-=lowb(i))
			ans+=c[i];
		return ans;
	}
}bit;
void solve(int l,int r,int ql,int qr){
	if(ql>qr)return;
	if(l==r){
		for(int i=ql;i<=qr;++i)
			if(q[i].type==2)
				ans[q[i].id]=l;
		return;
	}
	int mid=l+r>>1,cnt1=0,cnt2=0;
	for(int i=ql;i<=qr;++i){
		if(q[i].type==1){
			if(q[i].l<=mid){
				bit.add(q[i].id,1);
				q1[++cnt1]=q[i];
			}else
				q2[++cnt2]=q[i];
		}else{
			int x=bit.ask(q[i].r)-bit.ask(q[i].l-1);
			if(q[i].k<=x)
				q1[++cnt1]=q[i];
			else{
				q[i].k-=x;
				q2[++cnt2]=q[i];//减去左对右的贡献
			}
		}
	}
	//roll back
	for(int i=1;i<=cnt1;++i)			 
		if(q1[i].type==1)
			bit.add(q1[i].id,-1);
	for(int i=1;i<=cnt1;++i)q[ql+i-1]=q1[i];
	for(int i=1;i<=cnt2;++i)q[ql+cnt1+i-1]=q2[i];
	solve(l,mid,ql,ql+cnt1-1);
	solve(mid+1,r,ql+cnt1,qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	cnt=unique(b+1,b+1+n)-(b+1);
	for(int i=1;i<=n;++i){
		int x=lower_bound(b+1,b+1+cnt,a[i])-b;
		val[x]=a[i];
		a[i]=x;
	}
	for(int i=1;i<=n;++i){
		q[++tot]={a[i],-1,-1,i,1};
	}
	int l,r,k;
	for(int i=1;i<=m;++i){
		cin>>l>>r>>k;
		q[++tot]={l,r,k,i,2};
	}
	solve(1,cnt,1,tot);
	for(int i=1;i<=m;++i)cout<<val[ans[i]]<<"\n";
	return 0;
}