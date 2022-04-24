#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll dp[maxn];
int num[maxn],n,mx=0,mn=maxn,a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a;
        num[a]++;
        mx=max(mx,a);
        mn=min(mn,a);
    }
    dp[mn]=1ll*num[mn]*mn;
    for(int i=mn+1;i<=mx;++i){
        dp[i]=max(dp[i-2]+1ll*num[i]*i,dp[i-1]);
    }
    cout<<dp[mx]<<"\n";
    return 0;
}