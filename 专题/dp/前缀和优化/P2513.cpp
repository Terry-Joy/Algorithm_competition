#include<bits/stdc++.h>

using namespace std;
const int mod=10000;
int dp[mod+5][mod+5],sum,n,k;
int main(){ 
    dp[1][0]=1;
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;++i){ 
        sum=0;
        for(int j=0;j<=k;++j){ 
            sum+=dp[i-1][j];
            if(sum>=mod)sum-=mod;
            dp[i][j]=sum;
            if(j-i+1>=0){ 
                sum-=dp[i-1][j-i+1];
                if(sum<0)sum+=mod;
                if(sum>mod)sum%=mod;
            }
        }
    }
    cout<<dp[n][k]%mod<<endl;
    return 0;
}
