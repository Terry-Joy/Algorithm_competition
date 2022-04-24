#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[3010][3010];
int a[3010],b[3010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        a[i]-=i;
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int m=unique(b+1,b+n+1)-(b+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;++i)
        dp[1][i]=abs(a[1]-b[i]);
    for(int i=2;i<=n;++i){
        ll tmp=dp[i-1][0];
        for(int j=1;j<=m;++j){
            tmp=min(tmp,dp[i-1][j]);
            dp[i][j]=tmp+abs(a[i]-b[j]);
        }
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;++i)
        ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}