#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105];

int main(){
    int n,m,x1,x2,y1,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    dp[x1][y1] = 1;
    for(int i = x1; i < x2; ++i){//跳出去尼玛呢 草泥马傻逼数据 选题的能不能试一下
        for(int j = 1; j <= m; ++j){
            dp[i+1][j+2] += dp[i][j];
            dp[i+2][j+1] += dp[i][j];
            if(j-2 > 0) dp[i+1][j-2] += dp[i][j];
            if(j-1 > 0) dp[i+2][j-1] += dp[i][j];
        }
    }
    cout<<dp[x2][y2];
    return 0;
}
