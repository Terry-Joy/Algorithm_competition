#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
char s[110][110];
int dp[110][110];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>s[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1][1]=(s[1][1]=='#');
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
           if(i>1)dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i][j]=='#'&&s[i-1][j]=='.'));
           if(j>1)dp[i][j]=min(dp[i][j],dp[i][j-1]+(s[i][j]=='#'&&s[i][j-1]=='.')); 
        }
    cout<<dp[n][m];
	return 0;
} 
