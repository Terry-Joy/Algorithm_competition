#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r
#define ls k<<1
#define rs k<<1|1
int T;
string s;
int sum[200005][2];
struct seg{
	struct node{
		int l,r,mn,mx,lz;
	} s[800005];
	void build(int k,int l,int r,int type){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].mn=s[k].mx=sum[l][type];
			return;
		}
		int mid=(l+r)>>1;
		build(lson,type);
		build(rson,type);
		s[k].mn=min(s[ls].mn,s[rs].mn);
		s[k].mx=max(s[ls].mx,s[rs].mx);
	}
	void pushdown(int k){
		s[ls].mx+=s[k].lz;
		s[ls].mn+=s[k].lz;
		s[ls].lz+=s[k].lz;
		s[rs].mx+=s[k].lz;
		s[rs].mn+=s[k].lz;
		s[rs].lz+=s[k].lz;
        s[k].lz=0;
	}
	inline void change(int k,int l,int r,int val){
		if(l>r)	return;
		if(l<=s[k].l&&s[k].r<=r){
			s[k].lz+=val;
			s[k].mx+=val;
			s[k].mn+=val;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
        if(l<=mid)change(ls,l,r,val);
        if(r>mid)change(rs,l,r,val);
		s[k].mn=min(s[ls].mn,s[rs].mn);
		s[k].mx=max(s[ls].mx,s[rs].mx);
	}
	inline int query_mn(){
		return s[1].mn;
	}
	inline int query_mx(){
		return s[1].mx;
	}
} st[2];
int area(){
	return (max(st[0].query_mx(),0ll)-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),0ll)+1);
}
signed main(){
	cin>>T;
	while(T--){
		cin>>s;
		s=" "+s;
		for(int i=0;i<=s.size();i++)	sum[i][0]=sum[i][1];
		for(int i=1;i<s.size();i++){
			sum[i][0]=sum[i-1][0];
			sum[i][1]=sum[i-1][1];
			if(s[i]=='W')	sum[i][0]++;
			if(s[i]=='A')	sum[i][1]--;
			if(s[i]=='S')	sum[i][0]--;
			if(s[i]=='D')	sum[i][1]++;
		}
		st[0].build(1,1,s.size()-1,0);
		st[1].build(1,1,s.size()-1,1);
		int ans=area();
		for(int i=0;i<=s.size();i++){
			st[0].change(1,i,s.size()-1,-1);
			ans=min(ans,(max(st[0].query_mx(),0ll)-min(st[0].query_mn(),min(sum[i-1][0]-1,0ll))+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),0ll)+1));
			st[0].change(1,i,s.size()-1,1);
			st[0].change(1,i,s.size()-1,1);
			ans=min(ans,(max(st[0].query_mx(),max(sum[i-1][0]+1,0ll))-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),0ll)+1));
			st[0].change(1,i,s.size()-1,-1);
			st[1].change(1,i,s.size()-1,-1);
			ans=min(ans,(max(st[0].query_mx(),0ll)-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),min(sum[i-1][1]-1,0ll))+1));
			st[1].change(1,i,s.size()-1,1);
			st[1].change(1,i,s.size()-1,1);
			ans=min(ans,(max(st[0].query_mx(),0ll)-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),max(sum[i-1][1]+1,0ll))-min(st[1].query_mn(),0ll)+1));
			st[1].change(1,i,s.size()-1,-1);
		}
        printf("%lld\n",ans);
	}
	return 0;
}
