#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
const int INF=1e9;
int n,m,num[maxn],w[maxn],v[maxn];
int dp[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&num[i],&w[i],&v[i]);
    int ans=-INF;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            for(int k=1;k<=num[i];k++){
                if(k*w[i]>j)break;
                if(j>=k*w[i])dp[j]=max(dp[j],dp[j-w[i]*k]+v[i]*k);
                ans=max(ans,dp[j]);
            }
	cout<<ans<<"\n";
    return 0;
}