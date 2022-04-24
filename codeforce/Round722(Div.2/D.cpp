#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int f[maxn],dp[maxn],sum;
const int mod=998244353;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            f[j]++;
    dp[1]=1;
    sum=1;
    for(int i=2;i<=n;++i){
        dp[i]=(sum+f[i])%mod;
        sum=(sum+dp[i])%mod;
    }
    cout<<dp[n]<<"\n";
    return 0;
}