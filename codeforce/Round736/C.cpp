#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int cnt[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,q,u,v,ans=0,op;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		if(u>v)swap(u,v);
		if(!cnt[u])ans++;
		cnt[u]++;
	}	
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>op;
		if(op==1){
			cin>>u>>v;
			if(u>v)swap(u,v);
			if(!cnt[u])ans++;
			cnt[u]++;
		}else if(op==2){
			cin>>u>>v;
			if(u>v)swap(u,v);
			cnt[u]--;
			if(!cnt[u])ans--;
		}else{
			cout<<n-ans<<"\n";
		}
	}
	return 0;
}