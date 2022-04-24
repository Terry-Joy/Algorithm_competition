#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
double dp[maxn];
int n,m;
int main(){ 
    scanf("%d%d",&n,&m);
    dp[1]=1.0;
    for(int i=1;i<=m;++i)
        dp[i]=(dp[i-1]+1)*1.0*(n-dp[i-1])/n+dp[i-1]*1.0*dp[i-1]/n;
    printf("%.11lf",dp[m]);
    return 0;
}
