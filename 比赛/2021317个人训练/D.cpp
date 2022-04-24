#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll a[maxn],dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1];
        for(int j=0;j<=50;++j){
            if(a[i]&(1ll<<j)){
                dp[i]=max(dp[i],dp[pre[j]]+a[pre[j]]&a[i]);
                pre[j]=i;
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}