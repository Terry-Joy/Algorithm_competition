#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=102;
int n,k,mod,res;
ll dp[maxn][maxn*maxn*maxn];
void init(){
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        int up=k*((i+1)*i/2);
        for(int j=0;j<=up;++j){
            dp[i][j]=dp[i-1][j];
            if(j>=i){
                dp[i][j]+=dp[i][j-i];
                if(dp[i][j]>=mod)dp[i][j]-=mod;
            }
        }
        for(int j=up;j>=(k+1)*i;--j){
            dp[i][j]-=dp[i][j-(k+1)*i];
            if(dp[i][j]<0)
                dp[i][j]+=mod;
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&mod);
    init();
    for(int i=1;i<=n;++i){
        ll ans=0;
        int res1=i-1,res2=n-i;
        res=min(k*(res1*(res1+1)/2),k*(res2*(res2+1)/2));
        for(int j=0;j<=res;++j){
            ans=(ans+dp[res1][j]*dp[res2][j]%mod)%mod;
        }
        ans=(ans*(k+1)%mod-1+mod)%mod;
        cout<<ans<<"\n";
    }
}