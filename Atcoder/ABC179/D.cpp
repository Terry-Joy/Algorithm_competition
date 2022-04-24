#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const ll mod=998244353;
ll dp[maxn],sum[maxn];
int l[12],r[12];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i)scanf("%d%d",&l[i],&r[i]);
    sum[1]=dp[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=k;++j){
            int l1=l[j],r1=r[j];
            dp[i]=(dp[i]+(sum[max(0,i-l1)]-sum[max(0,i-r1-1)]+mod))%mod;
        }
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}