#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn=5e3+5;
const db eps=1e-9;
int n,r,m,d[60],t[60];
db p[maxn],dp[60][maxn];
db solve(db x){
    for(int i=m;i>=0;--i)
        for(int j=0;j<=r-n-1;++j){
            dp[i][j]=p[i]*(t[i+1]-t[i]+dp[i+1][j]);
            if(j+d[i]<=r-n-1)
                dp[i][j]+=(1-p[i])*(min(x,t[i+1]-t[i]+d[i]+dp[i+1][j+d[i]]));
            else
                dp[i][j]+=(1-p[i])*x;
        }
    return dp[0][0];
}
int main(){
    scanf("%d%d%d",&n,&r,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%lf%d",&t[i],&p[i],&d[i]);
    }
    p[0]=p[m+1]=1.0;
    t[m+1]=n;
    db l=0,r=2e9;
    for(int i=1;i<=60;++i)
    {
        db mid=(l+r)/2.0;
        if(solve(mid)<mid)r=mid;
        else l=mid;
    }
    printf("%.8f\n",l);
    return 0;
}