#include<bits/stdc++.h>

using namespace std;
const int maxn=1005;
double dp[maxn][maxn];
double a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
const double eps=1e-6;
int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)dp[i][j]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){
                scanf("%lf%lf%lf",&a[i][j],&b[i][j],&c[i][j]);
            }
        for(int i=n;i>=1;--i)
            for(int j=m;j>=1;--j){
                if(i==n&&j==m){
                    dp[i][j]=0;continue;
                }
                if(fabs(a[i][j]-1.00)<eps)continue;//!无路可走转移不了 一定要看清分母！
                dp[i][j]=2/(1.0-a[i][j])+b[i][j]/(1-a[i][j])*dp[i][j+1]+c[i][j]/(1-a[i][j])*dp[i+1][j];
            }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}