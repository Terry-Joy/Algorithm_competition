#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int q[maxn],h,t,n,l,r,a[maxn],dp[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l>>r;
    for(int i=0;i<=n;++i)cin>>a[i];
    for(int i=0;i<=n;++i)dp[i]=-2e9;
    dp[0]=0;
    h=1,t=0;
    q[++t]=0;
    int ans=-2e9;
    for(int i=l;i<=n;++i){ 
        while(h<=t&&dp[q[t]]<=dp[i-l])--t;
        q[++t]=i-l;
        while(h<=t&&q[h]<i-r)h++;
        dp[i]=dp[q[h]]+a[i];
        if(i>n-r)ans=max(dp[i],ans);//最后的转移注意一下，要越出去，=的时候还可以在转移一次
    }
    cout<<ans;
    return 0;
}
