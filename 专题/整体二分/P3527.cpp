#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll=long long;
const int maxn=6e5+5;
struct OPT{
	int k,id;
}q[maxn],q1[maxn],q2[maxn];
struct P{
	int l,r,num;
}e[maxn];
vector<int>pos[maxn];
int ans[maxn],n,m,x;
struct BIT{
	int N;
	ll c[maxn];
	#define lowb(i) (i&(-i))
	void init(int n){
		N=n;
	}
	void add(int x,int val){
		for(int i=x;i<=N;i+=lowb(i))
			c[i]+=val;
	}
	ll ask(int x){
		ll ans=0;
		for(int i=x;i;i-=lowb(i))
			ans+=c[i];
		return ans;
	}
}bit;
ll query(int x,int val){
	ll ans=0;
	for(auto&u:pos[x]){
		ans+=bit.ask(u)+bit.ask(u+m);
		if(ans>=val)return ans;
	}
	return ans;
}
void solve(int l,int r,int ql,int qr){
	if(l>r||ql>qr)return;
	if(l==r){
		for(int i=ql;i<=qr;++i)	
			ans[q[i].id]=l;
		return;
	}
	int mid=l+r>>1,cnt1=0,cnt2=0;
	for(int i=l;i<=mid;++i)
		bit.add(e[i].l,e[i].num),bit.add(e[i].r+1,-e[i].num);
	for(int i=ql;i<=qr;++i){
		ll sum=query(q[i].id,q[i].k);
		if(sum<q[i].k){
			q[i].k-=sum;
			q2[++cnt2]=q[i];
		}else
			q1[++cnt1]=q[i];
	}
	for(int i=l;i<=mid;++i)
		bit.add(e[i].l,-e[i].num),bit.add(e[i].r+1,e[i].num);
	for(int i=1;i<=cnt1;++i)q[i+ql-1]=q1[i];
	for(int i=1;i<=cnt2;++i)q[ql+i+cnt1-1]=q2[i];
	solve(l,mid,ql,ql+cnt1-1);
	solve(mid+1,r,ql+cnt1,qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x;
		pos[x].eb(i);
	}
	for(int i=1;i<=n;++i){
		cin>>q[i].k;
		q[i].id=i;
	}
	int cnt;
	cin>>cnt;
	for(int i=1;i<=cnt;++i){
		cin>>e[i].l>>e[i].r>>e[i].num;
		e[i].r=(e[i].r<e[i].l)?e[i].r+m:e[i].r;
	}
	bit.init(2*m+1);
	e[cnt+1].l=e[cnt+1].r=2*m+1;
	solve(1,cnt+1,1,n);
	for(int i=1;i<=n;++i){
		if(ans[i]==cnt+1)
			cout<<"NIE\n";
		else
			cout<<ans[i]<<"\n";
	}
	return 0;
}