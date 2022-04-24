#include<bits/stdc++.h>

using namespace std;
const int maxn=305;
int n,m,dp[maxn][maxn],x;
vector<int>G[maxn];
void dfs(int x){ 
    for(auto&v:G[x]){ 
        dfs(v);
        for(int j=m+1;j>=1;--j){ //分组压维背包倒序枚举
            for(int k=1;k<j;++k)//本身必须选
            dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k]);//选和不选
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){ 
        scanf("%d%d",&x,&dp[i][1]);
        G[x].push_back(i);
    }
    dfs(0);
    cout<<dp[0][m+1]<<endl;
    return 0;
}
