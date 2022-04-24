#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,dp[maxn][maxn];
struct P{
    int x,val;
    bool operator<(const P&a)const{return x<a.x;}
}a[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].val);
    sort(a+1,a+1+n);
    int ans=0;
    for(int j=1;j<=n;++j){
        int k=j-1,val=a[j].val;
        for(int i=j+1;i<=n;++i){
            while(k&&a[i].x-a[j].x>=a[j].x-a[k].x){
                val=max(dp[j][k],val);
                k--;
            }
            dp[i][j]=max(dp[i][j],val+a[i].val);
            ans=max(ans,dp[i][j]);
        }
    }
    memset(dp,0,sizeof(dp));
    for(int j=n;j>=1;--j){
        int k=j+1,val=a[j].val;
        for(int i=j-1;i>=1;--i){
            while(k<=n&&a[j].x-a[i].x>=a[k].x-a[j].x){
                val=max(dp[j][k],val);
                k++;
            }
            dp[i][j]=max(dp[i][j],val+a[i].val);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}