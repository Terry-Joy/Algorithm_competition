#include<bits/stdc++.h>
using namespace std;
typedef double db;
db dp[105][105];
int main(){
    int n;
    scanf("%d",&n);
    dp[0][0]=100;
    db tmp=0;
    for(int i=1;i<=n;++i){
        scanf("%lf",&tmp);
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]*100.0/tmp);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]*1.0*tmp/100);
    }
    printf("%.0f",floor(dp[n][0]));
    return 0;
}