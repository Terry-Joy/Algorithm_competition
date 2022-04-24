#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=9999973;
ll dp[105][105][105];
int main(){ 
    int n,m;
    cin>>n>>m;
    dp[0][0][0]=1;
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<=m;++j){ 
            for(int k=0;k<=m-j;++k){ 
                dp[i][j][k]=dp[i-1][j][k];
                if(j>=1){ 
                    dp[i][j][k]+=dp[i-1][j-1][k]*(m-k-j+1);
                    dp[i][j][k]%=mod;
                }
                if(k>=1){ 
                    dp[i][j][k]+=dp[i-1][j+1][k-1]*(j+1);
                    dp[i][j][k]%=mod;
                }
                if(j>=2){ 
                    dp[i][j][k]+=dp[i-1][j-2][k]*(m-k-j+2)*(m-k-j+1)/2;
                    dp[i][j][k]%=mod;
                }
                if(k>=2){ 
                    dp[i][j][k]+=dp[i-1][j+2][k-2]*(j+1)*(j+2)/2;
                    dp[i][j][k]%=mod;
                }
                if(j>=1&&(m-(k-1)-j>=1)){ 
                    dp[i][j][k]+=dp[i-1][j][k-1]*(m-(k-1)-j)*j;
                    dp[i][j][k]%=mod;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=m;++i){ 
        int f=m-i;
        for(int j=0;j<=f;++j){ 
            ans+=dp[n][i][j];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
