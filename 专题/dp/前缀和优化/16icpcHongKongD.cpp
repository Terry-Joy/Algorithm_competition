#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[72][72][72*142];
ll mn[72][72][72*142];
ll a[72*142],p[72],c[72];
int n,K,cnt,m;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>K;
    for(int i=1;i<=n;++i){ 
        cin>>p[i]>>c[i];
        for(int j=-n;j<=n;++j){ 
            if(p[i]+j>0)
                a[++cnt]=p[i]+j;
        }
    }
    sort(a+1,a+1+cnt);
    m=unique(a+1,a+1+cnt)-(a+1);
    for(int i=1;i<=n;++i)
        for(int j=0;j<=K;++j)
            for(int k=1;k<=m;++k)dp[i][j][k]=INF;
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=K;++j){//第一个必定被看见 枚举到后面的第一个不可能不被看见 
            for(int k=1;k<=m;++k){ 
                if(i==1){ 
                    if(j==1)dp[i][j][k]=c[i]*abs(p[i]-a[k]);
                }else{ 
                    if(p[i]<=a[k])dp[i][j][k]=mn[i-1][j][k];//当前是k依然可以不选
                    else dp[i][j][k]=mn[i-1][j][k]+c[i]*(p[i]-a[k]);//看不见
                    if(j>=2&&k>=2)//当前能看见 只有在j>=2的时候看才有必要转移 此时最小值已经被占据
                        dp[i][j][k]=min(dp[i][j][k],mn[i-1][j-1][k-1]+c[i]*abs(p[i]-a[k]));
                }
                mn[i][j][k]=dp[i][j][k];
                if(k>=2)
                    mn[i][j][k]=min(mn[i][j][k-1],mn[i][j][k]);
            }
        }
    }
    cout<<mn[n][K][m]<<endl;
    return 0;
}
