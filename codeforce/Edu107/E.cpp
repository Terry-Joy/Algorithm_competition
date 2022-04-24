#include<bits/stdc++.h>
#define pb push_back 
#define fi first  
#define se second
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
const ll mod=998244353;
int n,m;
ll dp[maxn],pow2[maxn],ans=0;
string s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>s[i];
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            cnt+=(s[i][j]=='o');
        }
    }
    pow2[0]=1;
    for(int i=1;i<=n*m;++i){
        pow2[i]=pow2[i-1]*2%mod;
    }
    dp[0]=dp[1]=0;dp[2]=1;
    for(int i=3;i<=n*m;++i){
        dp[i]=(dp[i-1]+2*dp[i-2]+pow2[i-2])%mod;
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        int len=0;
        for(int j=0;j<m;++j){
            if(s[i][j]=='*')len=0;
            else len++;
            if(s[i][j+1]=='*'||j+1>=m){
                ans=(ans+dp[len]*pow2[cnt-len]%mod)%mod;
            }
        }
    }
    for(int j=0;j<m;++j){
        int len=0;
        for(int i=1;i<=n;++i){
            if(s[i][j]=='*')len=0;
            else len++;
            if(s[i+1][j]=='*'||i+1>n){
                ans=(ans+dp[len]*pow2[cnt-len]%mod)%mod;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}