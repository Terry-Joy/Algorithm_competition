#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,s,T[maxn],F[maxn],S,dp[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>S;
    for(int i=1;i<=n;++i)cin>>T[i]>>F[i];
    for(int i=1;i<=n;++i)T[i]+=T[i-1],F[i]+=F[i-1];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<i;++j){ 
            dp[i]=min(dp[i],dp[j]+T[i]*(F[i]-F[j])+S*(F[n]-F[j]));
        }
    }
    cout<<dp[n];
    return 0;
}
