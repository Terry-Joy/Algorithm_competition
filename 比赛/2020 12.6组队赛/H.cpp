#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<double,double>P;
int t,n,m;
const int maxn=305;
double dp[maxn][maxn][2];
P p[maxn];
double d[maxn][maxn];
double dis(P a,P b){ 
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%lf%lf",&p[i].fi,&p[i].se);
        memset(dp,0,sizeof(dp));
        memset(d,0,sizeof(d));
        scanf("%d",&m);
        for(int i=1;i<=m;++i){ 
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            dp[x][y][0]=dp[x][y][1]=dp[y][x][0]=dp[y][x][1]=d[x][y]=d[y][x]=dis(p[x],p[y]);
        }
        for(int len=n-1;len>=1;--len){ 
            for(int i=0;i<n;++i){ 
                int j=(i+len)%n;
                int st=(i+1)%n;
                for(int k=st;k!=j;k=(k+1)%n){ 
                    dp[i][k][1]=max(dp[i][j][1]+d[j][k],dp[i][k][1]);
                    dp[k][j][0]=max(dp[i][j][1]+d[j][k],dp[k][j][0]);
                    dp[i][k][1]=max(dp[i][j][0]+d[i][k],dp[i][k][1]);
                    dp[k][j][0]=max(dp[i][j][0]+d[i][k],dp[k][j][0]);
                }
            }
        }
        double ans=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
        printf("%.12f\n",ans);
    }
    return 0;
}
