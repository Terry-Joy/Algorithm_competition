#include<bits/stdc++.h>

using namespace std;
const int maxn=4e4+5;
int n,v[105],w[105],m[105],V,dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>V;
    for(int i=1;i<=n;++i)cin>>v[i]>>w[i]>>m[i];
    for(int i=1;i<=n;++i){
        if(w[i]*m[i]>=V){
            for(int j=w[i];j<=V;++j)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            continue;
        }
        for(int j=1;m[i];j<<=1){
            if(m[i]<j)j=m[i];
            m[i]-=j;
            int a=j*w[i],b=j*v[i];
            for(int k=V;k>=a;--k)
                dp[k]=max(dp[k],dp[k-a]+b);
        }
    }
    cout<<dp[V];
    return 0;
}