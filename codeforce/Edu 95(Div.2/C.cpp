#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int INF=0x3f3f3f3f;
int dp[maxn][2],a[maxn];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)dp[i][0]=dp[i][1]=INF;
        dp[1][0]=a[1];
        dp[0][1]=0;
        dp[0][0]=INF;
        for(int i=2;i<=n;++i){ 
            dp[i][0]=min(dp[i-1][1]+a[i],dp[i-2][1]+a[i]+a[i-1]);
            dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
        }
        cout<<min(dp[n][0],dp[n][1])<<endl;
    }
    return 0;
}
