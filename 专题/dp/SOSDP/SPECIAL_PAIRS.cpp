#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=(1<<21)+100;
const int maxm=1e5+10;
int cnt[maxn],dp[maxn],a[maxm];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){ 
        cin>>n;
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;++i){ 
            cin>>a[i];
            dp[a[i]]=++cnt[a[i]];
        }
        for(int i=0;i<=20;++i){ 
            for(int j=0;j<(1<<21);++j){ 
                if(j&(1<<i)){ 
                    dp[j]+=dp[j^(1<<i)];
                }
            }
        }
        ll ans=0;
        for(int i=0;i<(1<<21);++i){ 
            ans+=(ll)cnt[i]*dp[(1<<21)-1-i];
        }
    }
    return 0;
}
