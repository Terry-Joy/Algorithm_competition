#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
typedef long long ll;
char s[maxn];
const ll mod=1e9+7;
ll dp[maxn][2][2];
int main(){ 
    scanf("%s",s+1);
    int n=strlen(s+1);
    dp[0][0][0]=1;dp[0][0][1]=1;
    for(int i=1;i<=n;++i){ 
        if(s[i]=='0'){ 
            dp[i][0][0]+=dp[i-1][0][0];
            dp[i][0][0]%=mod;
        }else if(s[i]=='1'){ 
            dp[i][0][1]+=dp[i-1][0][0];
            dp[i][0][0]+=dp[i-1][1][0];
            dp[i][0][1]%=mod;
            dp[i][0][0]%=mod;
        }else if(s[i]=='2'){ 
            dp[i][0][1]+=dp[i-1][1][0];
            dp[i][0][1]%=mod;
        }else if(s[i]=='*'){ 
            dp[i][1][0]+=(dp[i-1][0][1]+dp[i-1][1][1]);
            dp[i][1][0]%=mod;
            dp[i][1][1]+=(dp[i-1][0][1]+dp[i-1][1][1]);
            dp[i][1][1]%=mod;
        }else if(s[i]=='?'){ 
            dp[i][1][0]+=(dp[i-1][0][1]+dp[i-1][1][1]);
            dp[i][1][1]+=(dp[i-1][0][1]+dp[i-1][1][1]);
            dp[i][0][0]+=(dp[i-1][0][0]+dp[i-1][1][0]);
            dp[i][0][1]+=(dp[i-1][0][0]+dp[i-1][1][0]);
            dp[i][1][0]%=mod,dp[i][1][1]%=mod,dp[i][0][0]%=mod,dp[i][0][1]%=mod;
        }
    }
    cout<<(dp[n][1][0]+dp[n][0][0])%mod<<endl;
    return 0;
}
