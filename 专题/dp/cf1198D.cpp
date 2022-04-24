#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[55][55],dp[55][55][55][55],n;
char s[52][52];
int dfs(int x1,int y1,int x2,int y2){
    if(~dp[x1][y1][x2][y2])return dp[x1][y1][x2][y2];
    dp[x1][y1][x2][y2]=max(x2-x1+1,y2-y1+1);
    int k=sum[x2][y2]-sum[x1-1][y1]-sum[x1][y1-1]+sum[x1-1][y1-1];
    if(k==0)return dp[x1][y1][x2][y2]=0;
    else if(k==(x2-x1+1)*(y2-y1+1))return dp[x1][y1][x2][y2];
    for(int i=x1;i<x2;++i)//x
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],dfs(x1,y1,i,y2)+dfs(i+1,y1,x2,y2));
    for(int i=y1;i<y2;++i)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],dfs(x1,y1,x2,i)+dfs(x1,i+1,x2,y2));
    return dp[x1][y1][x2][y2];
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='#');
    cout<<dfs(1,1,n,n);
    return 0;
}