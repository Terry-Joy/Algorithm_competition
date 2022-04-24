#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int dp[maxn],a[maxn],num[32];
int main(){
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),dp[i]=1;
    for(int i=0;i<30;++i){
        if((a[1]>>i)&1)num[i]=dp[1];
    }
    for(int i=2;i<=n;++i){
        for(int j=0;j<30;++j){
            if((a[i]>>j)&1)
                dp[i]=max(num[j]+1,dp[i]);
        }
        for(int j=0;j<30;++j){
            if((a[i]>>j)&1)
                num[j]=max(dp[i],num[j]);
        }
        ans=max(dp[i],ans);
    }
    cout<<ans<<"\n";
    return 0;
}