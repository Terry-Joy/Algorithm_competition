#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
double dp[105][105][105],fac[105],A[105][105],g[105][105],d[105];
int n;
int main(){ 
    cin>>n;
    fac[0]=fac[1]=1;
    for(int i=2;i<=n;++i)fac[i]=fac[i-1]*i;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            A[i][j]=fac[i]/fac[i-j];
    d[1]=0;d[2]=1;
    for(int i=3;i<=n;++i)d[i]=(i-1)*(d[i-1]+d[i-2]);
    for(int i=1;i<=n;++i){ 
        for(int j=2;j<=i;++j){ 
            if(i==j){ //第一个环
                dp[i][j][1]=A[n][i]/i;
            }
            else{ 
                for(int k=2;k<=j-1;++k){ //小环到大环
                    dp[i][j][1]+=g[i-j][k];
                }
                dp[i][j][1]*=A[n-(i-j)][j]/j;//i>j转移
            }
            for(int k=2;k*j<=i;++k)//环数增加
                dp[i][j][k]=dp[i-j][j][k-1]*A[n-(i-j)][j]/j/k;
        }
        for(int j=2;j<=i;++j)
            for(int k=1;k*j<=i;++k)
                g[i][j]+=dp[i][j][k];
    }
    double ans=0;
    for(int j=2;j<=n;++j)
        for(int k=1;k*j<=n;++k)
            ans+=j*k*dp[n][j][k];
    ans/=d[n];
    printf("%.14lf\n",ans);
    return 0;
}
