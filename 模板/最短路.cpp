//floyd 可判负环 边正负都可
void floyd(){
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    //传递闭包
    dp[i][j]|=dp[i][k]&dp[k][j];
}

