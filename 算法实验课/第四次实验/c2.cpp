#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,num[maxn],w[maxn],v[maxn],M,dp[maxn];
int main(){
	scanf("%d%d",&n,&M);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&num[i],&w[i],&v[i]);
	}
	for(int i=1;i<=n;++i){
		if(w[i]*num[i]>=M){
			for(int f=w[i];f<=M;++f)
				dp[f]=max(dp[f],dp[f-w[i]]+v[i]);
			continue;
		}
		for(int k=1;num[i];k<<=1){
			if(num[i]<k)k=num[i];
			num[i]-=k;
			int a=k*w[i],b=k*v[i];
			for(int f=M;f>=a;--f)
				dp[f]=max(dp[f],dp[f-a]+b);
		}
	}
	cout<<dp[M];
	return 0;
}