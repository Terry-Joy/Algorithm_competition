#include<bits/stdc++.h>

using namespace std;
const int maxn=505;
const int mod=1024523;
int dp[2][maxn][maxn],n,m;
char a[maxn],b[maxn];
void add(int &x,int y){ 
    x+=y;if(x>=mod)x-=mod;
}
int main(){ 
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    scanf("%s",b+1);
    dp[0][0][0]=1;
    for(int i=0;i<n+m;++i){ 
        int mx=min(i,n);
        for(int j=0;j<=mx;++j){ 
            for(int k=0;k<=mx;++k){ 
                if(!dp[i&1][j][k])continue;
                if(a[j+1]==a[k+1])
                    add(dp[(i+1)&1][j+1][k+1],dp[i&1][j][k]);       //两边都选上面的
                if(a[j+1]==b[i+1-k])
                    add(dp[(i+1)&1][j+1][k],dp[i&1][j][k]);       //上下
                if(b[i+1-j]==b[i+1-k])
                    add(dp[(i+1)&1][j][k],dp[i&1][j][k]);       //下下
                if(b[i+1-j]==a[k+1])
                    add(dp[(i+1)&1][j][k+1],dp[i&1][j][k]);       //下上
                dp[i&1][j][k]=0;
            }
        }
    }
    cout<<dp[(n+m)&1][n][n];
    return 0;
}
