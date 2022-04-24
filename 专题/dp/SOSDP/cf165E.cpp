#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<22)+100;
const int INF=0x3f3f3f3f;
int n,a[maxn],dp[maxn];
const int inf=(1<<22)-1;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int lim=(1<<22);
    for(int i=0;i<lim;++i)dp[i]=INF;
    for(int i=1;i<=n;++i)cin>>a[i],dp[a[i]]=a[i];
    for(int i=0;i<22;++i){ 
        for(int j=1;j<=inf;++j){ 
            if((j&(1<<i))&&(dp[j^(1<<i)]!=INF))
                dp[j]=min(dp[j],dp[j^(1<<i)]);
        }
    }
    
    for(int i=1;i<=n;++i){ 
        if(dp[inf^a[i]]!=INF)
            cout<<dp[inf^a[i]]<<" ";
        else cout<<-1<<" ";
    }
    return 0;  
}
