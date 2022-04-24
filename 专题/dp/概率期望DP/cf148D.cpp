#include<bits/stdc++.h>

using namespace std;
const int maxn=1005;
const double eps=1e-9;
double dp[maxn][maxn];
int main(){ 
    int w,b;
    scanf("%d%d",&w,&b);
    for(int i=1;i<=w;++i)dp[i][0]=1.0;
    for(int i=1;i<=w;++i)
        for(int j=1;j<=b;++j){ 
            dp[i][j]=1.0*i/(i+j);
            if(j>=3)
                dp[i][j]+=j*1.0/(i+j)*(j-1)*1.0/(i+j-1)*(j-2)*1.0/(i+j-2)*dp[i][j-3];
            if(j>=2)
                dp[i][j]+=j*1.0/(i+j)*(j-1)*1.0/(i+j-1)*1.0*i/(i+j-2)*dp[i-1][j-2];
        }
    printf("%.9lf\n",dp[w][b]);
    return 0;
}
