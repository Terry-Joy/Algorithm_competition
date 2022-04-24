#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double p[256][256],dp[10][256];
int n;
int main(){ 
    while(~scanf("%d",&n)&&n!=-1){ 
        memset(dp,0,sizeof(dp));
        int len=1<<n;
        for(int i=0;i<len;++i)
            for(int j=0;j<len;++j)
                scanf("%lf",&p[i][j]);
        for(int i=0;i<len;++i)dp[0][i]=1.0;
        for(int i=1;i<=n;++i)
            for(int j=0;j<len;++j)
                for(int k=0;k<len;++k){ 
                    if(j==k)continue;
                    if(((j>>(i-1))^1)==(k>>(i-1)))
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
                }
        int k=0;
        double mx=-1;
        for(int i=0;i<len;++i){ 
            if(dp[n][i]>mx){ 
                mx=dp[n][i];
                k=i;
            }
        }
        cout<<k+1<<"\n";
    }
    return 0;
}
