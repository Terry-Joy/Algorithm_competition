#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+5;
const int mod=1e9+7;
int n,t,m;
char s[20];
int dp[maxn][20],sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    dp[0][9]=1;
    for(int i=1;i<=200000;++i){
        dp[i][0]=dp[i-1][9]%mod;
        dp[i][1]=(dp[i-1][9]+dp[i-1][0])%mod;
        for(int j=2;j<=9;++j)
            dp[i][j]=dp[i-1][j-1]%mod;
        for(int j=0;j<=9;++j){
            sum[i]+=dp[i][j];
            sum[i]%=mod; 
        }
    }
    while(t--){
        cin>>n>>m;
        ll ans=0;
        while(n){
            int xx=n%10;
            if(xx+m<=9)ans++;
            else 
                ans+=sum[m-(9-xx)];
            ans%=mod;
            n/=10;
        }   
        cout<<ans<<"\n";
    }
    return 0;
}