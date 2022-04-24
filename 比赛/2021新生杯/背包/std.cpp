#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5005,N=maxn*maxn;
struct P{
	ll w,v;
	bool operator<(const P&x)const{
		return w==x.w?v>x.v:w<x.w;
	}
}a[maxn],dp[N],tmp[N],c[N];
int n,cnt,t;
ll m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n>>m;
		if(!n){
			cout<<0;return 0;
		}
		for(int i=0;i<n;++i){
			cin>>a[i].w>>a[i].v;
		}
		ll ans=0;
		dp[++cnt]={0,0};
		for(int i=0;i<n;++i){
			int num=0;
			ll w=a[i].w,v=a[i].v;
			for(int i=1;i<=cnt;++i){
				if(w+dp[i].w<=m){
					tmp[++num]={w+dp[i].w,v+dp[i].v};
				}
			}
			merge(dp+1,dp+1+cnt,tmp+1,tmp+1+num,c+1);
			int tmpcnt=cnt;
			cnt=0;
			for(int i=1;i<=tmpcnt+num;++i){
				if(i==1||c[i].v>dp[cnt].v)
					dp[++cnt]=c[i];
			}
			ans=max(ans,dp[cnt].v);
		}
		cout<<ans<<"\n";
	}
	return 0;
}