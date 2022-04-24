#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
ll dp[maxn][4];
char s[maxn];
int main(){ 
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        if(s[i]=='a'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=(dp[i-1][1]+dp[i-1][0])%mod;
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }else if(s[i]=='b'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=(dp[i-1][2]+dp[i-1][1])%mod;
            dp[i][3]=dp[i-1][3];
        }else if(s[i]=='c'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=(dp[i-1][3]+dp[i-1][2])%mod;
        }else{
            for(int j=1;j<=3;++j)
                dp[i][j]=(3*dp[i-1][j]+dp[i-1][j-1])%mod;
            dp[i][0]=dp[i-1][0]*3%mod;
        }
    }
    cout<<dp[n][3]<<endl;
    return 0;
}
