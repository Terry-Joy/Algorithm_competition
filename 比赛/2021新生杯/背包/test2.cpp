#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5100,M=100000010,LEN=6000010;
ll m,f[M],ans;int n,i,cnt;
inline void up(ll&a,ll b){a<b?(a=b):0;}
bool cmp1(pair<ll,ll>&a,pair<ll,ll>&b){
	return a.second>b.second;
}
bool cmp2(pair<ll,ll>&a,pair<ll,ll>&b){
	return a.first>b.first;
}
bool cmp3(pair<ll,ll>&a,pair<ll,ll>&b){
	return 1.0*a.second/a.first>1.0*b.second/b.first;
}
int main(){
	ll nowans=0;
	//freopen("data.in","r",stdin);
	//freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<pair<ll,ll>>mp;
	while(n--){
		ll w;ll v;
		scanf("%lld%lld",&w,&v);
		if(w>m)continue;
		else mp.push_back({w,v});
		//for(i=m;i>=w;i--)up(f[i],f[i-w]+v);
	}
//	sort(mp.begin(),mp.end(),cmp1);
	int T=100000;
	for(int i=1;i<=T;++i){	
		ll ans=0,num=0;
		random_shuffle(mp.begin(),mp.end());
		for(auto&[u,v]:mp){
			if(num+u<=m){
				ans+=v;
				num+=u;
			}
		}
		nowans=max(nowans,ans);
	}
	// sort(mp.begin(),mp.end(),cmp2);
	// //int T=10000;
	// for(int i=1;i<=T;++i){	
	// 	ll ans=0,num=0;
	// 	random_shuffle(mp.begin(),mp.end());
	// 	for(auto&[u,v]:mp){
	// 		if(num+u<=m){
	// 			ans+=v;
	// 			num+=u;
	// 		}
	// 	}
	// 	nowans=max(nowans,ans);
	// }
	// sort(mp.begin(),mp.end(),cmp3);
	// //int T=10000;
	// for(int i=1;i<=T;++i){	
	// 	ll ans=0,num=0;
	// 	random_shuffle(mp.begin(),mp.end());
	// 	for(auto&[u,v]:mp){
	// 		if(num+u<=m){
	// 			ans+=v;
	// 			num+=u;
	// 		}
	// 	}
	// 	nowans=max(nowans,ans);
	// }
	cout<<nowans;
	//for(i=0;i<=m;i++)up(ans,f[i]);
	//printf("%lld",ans);
	return 0;
}
