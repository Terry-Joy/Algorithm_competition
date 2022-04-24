#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int sum[maxn][maxn],dp[maxn][maxn][maxn][maxn],n,m,a[maxn][maxn];
int getSum(int x1,int y1,int x2,int y2){ 
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j)cin>>a[i][j];
    }
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int h=1;h<=n;++h){ 
        for(int w=1;w<=m;++w){ 
            for(int x1=1;x1+h-1<=n;++x1){ 
                int x2=x1+h-1;
                for(int y1=1;y1+w-1<=m;++y1){ 
                    int y2=y1+w-1;
                    dp[x1][y1][x2][y2]=getSum(x1,y1,x2,y2);
                    if(h>1){ //不能被0转移
                        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],dp[x1+1][y1][x2][y2]);
                        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],dp[x1][y1][x2-1][y2]);
                    }
                    if(w>1){ 
                        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],dp[x1][y1+1][x2][y2]);
                        dp[x1][y1][x2][y2]=max(dp[x1][y1][x2][y2],dp[x1][y1][x2][y2-1]);
                    }
                }
            }
        }
    }
    int ans=-2e9;
    for(int r1=1;r1<n;++r1){ 
        for(int r2=r1+1;r2<n;++r2)
            ans=max(ans,dp[1][1][r1][m]+dp[r1+1][1][r2][m]+dp[r2+1][1][n][m]);
    }
    for(int c1=1;c1<m;++c1){ 
        for(int c2=c1+1;c2<m;++c2)
            ans=max(ans,dp[1][1][n][c1]+dp[1][c1+1][n][c2]+dp[1][c2+1][n][m]);
    }
    for(int r1=1;r1<n;++r1){ 
        for(int c1=1;c1<m;++c1){ 
            ans=max(ans,dp[1][1][r1][c1]+dp[1][c1+1][r1][m]+dp[r1+1][1][n][m]);//上二下一
            ans=max(ans,dp[r1+1][1][n][c1]+dp[r1+1][c1+1][n][m]+dp[1][1][r1][c1]);//上一下二
            ans=max(ans,dp[1][c1+1][r1][m]+dp[r1+1][c1+1][n][m]+dp[1][1][n][c1]);//左一右二
            ans=max(ans,dp[1][1][r1][c1]+dp[r1+1][1][n][c1]+dp[1][c1+1][n][m]);//左二右一
        }
    }
    cout<<ans<<"\n";
    return 0;
}
