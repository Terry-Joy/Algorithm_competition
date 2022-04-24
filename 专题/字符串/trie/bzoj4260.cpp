#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int n,a[maxn],nxt[2][maxn*31+5][2],pre[maxn],suf[maxn],cnt[2]={1,1},sum[maxn];
void insert(int is,int x){
	int now=1;
	for(int i=31;i>=0;--i){
		int ch=(x>>i)&1;
		if(!nxt[is][now][ch])nxt[is][now][ch]=++cnt[is];
		now=nxt[is][now][ch];
	}
}
int query(int is,int x){
	int now=1,ans=0;
	for(int i=31;i>=0;--i){
		int ch=(x>>i)&1;
		if(nxt[is][now][ch^1])ans|=(1<<i),now=nxt[is][now][ch^1];
		else now=nxt[is][now][ch];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum[i]=a[i];
	for(int i=2;i<=n;++i){
		a[i]^=a[i-1];
	}
	for(int i=n-1;i>=1;--i){
		sum[i]^=sum[i+1];
	}
	// pre[1]=a[1];suf[n]=sum[n];
	// insert(0,a[1]);
	insert(0,0);
	// insert(1,sum[n]);
	insert(1,0);
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i){
		ans1=max(ans1,query(0,a[i]));
		pre[i]=max(pre[i-1],ans1);
		insert(0,a[i]);
	}
	for(int i=n;i>=1;--i){
		ans2=max(ans2,query(1,sum[i]));
		suf[i]=max(ans2,suf[i+1]);
		insert(1,sum[i]);
	}
	int ans=0;
	for(int i=1;i<=n-1;++i){
		ans=max(ans,pre[i]+suf[i+1]);
	}
	cout<<ans;
	return 0;
}