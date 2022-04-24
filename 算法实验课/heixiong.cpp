#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int dp[maxn],a[maxn],n;
int main(){
	int p,q;
	cin>>p>>q;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dp[0]=p;
	for(int i=1;i<=n+1;++i){
		if(dp[i-1]-q>=0)
			dp[i]=max(dp[i],dp[i-1]-q+a[i]);
		if(dp[i-2]-q>=0&&i-2>=0)
			dp[i]=max(dp[i],dp[i-2]-q+a[i]);
	}
	if(dp[n+1]==-1)puts("NO");
	else cout<<dp[n+1];
	return 0;
}