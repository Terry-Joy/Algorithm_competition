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
		for(int j=M;j>=w[i];--j)
			for(int k=1;k<=num[i];++k){
				if(k*w[i]>j)break;
					dp[j]=max(dp[j],dp[j-k*w[i]]+v[i]*k);
			}
	}
	cout<<dp[M];
	return 0;
}