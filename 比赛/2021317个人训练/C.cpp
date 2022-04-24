#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n;
ll dp[maxn],sum[maxn];
const ll mod=998244353;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)dp[i]=1;
    for(int i=1;i<=n;++i){
        dp[i]+=sum[i-1];
        int bit=1;
        while((2*bit)<i){
            if(i&bit)
                dp[i]=(dp[i]-(sum[2*bit-1]-sum[bit-1])+mod)%mod;
            bit<<=1;
        }
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<sum[n]<<"\n";
    return 0;
}