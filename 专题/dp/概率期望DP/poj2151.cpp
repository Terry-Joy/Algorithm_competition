#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double dp[1005][32][32],p[1005][32];
int M,t,n;
int main(){ 
    while(~scanf("%d%d%d",&M,&t,&n)){ 
        memset(dp,0,sizeof(dp));
        if(!M&&!t&&!n)break;
        double sum1=0,sum=1.0;
        for(int i=1;i<=t;++i)
            for(int j=1;j<=M;++j)
                scanf("%lf",&p[i][j]);
        for(int i=1;i<=t;++i)dp[i][0][0]=1.0;
        for(int i=1;i<=t;++i){ 
            sum1=0;
            for(int j=1;j<=M;++j){ 
                for(int k=0;k<=j;++k){ 
                    dp[i][j][k]+=dp[i][j-1][k]*(1-p[i][j]);
                    if(k>=1)
                        dp[i][j][k]+=dp[i][j-1][k-1]*p[i][j];
                }
            }
            for(int j=1;j<=M;++j)
                sum1+=dp[i][M][j];
            sum*=sum1;
        }
        double sum2=1.0;
        for(int i=1;i<=t;++i){ 
            double num=0;
            for(int j=1;j<=n-1;++j)
                num+=dp[i][M][j];
            sum2*=num;
        }
        printf("%.3f\n",sum-sum2);
    }
    return 0;
}
