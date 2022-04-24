#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int cnt[maxn],dp[maxn][3][3],n,m,mx=0,mn=maxn;
int main(){
    scanf("%d%d",&n,&m);
    int a;
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        cnt[a]++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=m;++i){
        for(int j=0;j<=2;++j){
            for(int k=0;k<=2;++k){
                for(int l=0;l<=2;++l){
                    if(cnt[i]<j+k+l||dp[i-1][k][l]==-1)continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+(cnt[i]-j-k-l)/3+j);
                }
            }
        }
    }
    cout<<dp[m][0][0];
    return 0;
}