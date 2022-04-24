#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int INF=2e9;
int n,a[maxn],Q,k,q[maxn],t,h,dp[maxn];
int main(){
    scanf("%d",&n); 
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&k);
        h=1;t=0;
        for(int i=1;i<=n;++i)dp[i]=INF;
        dp[1]=0;
        for(int i=1;i<=n;++i){
            while(h<=t&&q[h]<i-k)h++;
            dp[i]=min(dp[i],dp[q[h]]+(a[q[h]]<=a[i]));
            while(h<=t&&((dp[q[t]]>dp[i])||(dp[q[t]]==dp[i]&&a[i]>=a[q[t]])))t--;
            q[++t]=i;
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}