#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
const int INF=0x3f3f3f3f;
int m,d[maxn][maxn],p[1005],dp[2][maxn][maxn],n;
int main(){ 
    cin>>m;
    for(int i=1;i<=m;++i)
       for(int j=1;j<=m;++j)cin>>d[i][j];
    for(int i=0;i<=1;++i){ 
        for(int j=0;j<=m;++j)
            for(int k=0;k<=m;++k)dp[i&1][j][k]=INF;
    }
    int now=1;
    while(cin>>p[now++]);
    dp[0][1][2]=0; p[0]=3;
    for(int i=0;i<now;++i){
        for(int j=1;j<=m;++j)
           for(int k=1;k<=m;++k)dp[(i+1)&1][j][k]=INF; 
        for(int j=1;j<=m;++j)
            for(int k=1;k<=m;++k){ 
                if(j==k||dp[i&1][j][k]==INF)continue;
                dp[(i+1)&1][j][k]=min(dp[(i+1)&1][j][k],dp[i&1][j][k]+d[p[i-1]][p[i]]);
                dp[(i+1)&1][p[i-1]][k]=min(dp[(i+1)&1][p[i-1]][k],dp[i&1][j][k]+d[j][p[i]]);
                dp[(i+1)&1][j][p[i-1]]=min(dp[(i+1)&1][j][p[i-1]],dp[i&1][j][k]+d[k][p[i]]);
            }
    }
    int ans=INF;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=m;++j){ 
            if(i==j||j==p[now]||i==p[now])continue;
            ans=min(ans,dp[now&1][i][j]);
        }
    cout<<ans;
    return 0;
}
