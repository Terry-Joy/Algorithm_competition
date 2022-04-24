#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5*31+5;
const int maxm=1e5+5;
int nxt[maxn][2],a[maxm],cnt=1;
void insert(int x){
	int now=1;
	for(int i=31;i>=0;--i){
		int ch=(x>>i)&1;
		if(!nxt[now][ch])nxt[now][ch]=++cnt;
		now=nxt[now][ch];
	}
}
int query(int x){
	int now=1,ans=0;
	for(int i=31;i>=0;--i){
		int ch=(x>>i)&1;
		if(nxt[now][ch^1])ans|=(1<<i),now=nxt[now][ch^1];
		else now=nxt[now][ch];
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	insert(a[1]);
	int ans=0;
	for(int i=2;i<=n;++i){
		ans=max(ans,query(a[i]));
		insert(a[i]);
	}
	cout<<ans<<"\n";
	return 0;
}