#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
using P=pair<int,int>;
const int maxn=2e6+10;
P dp[maxn];
int n,a[maxn];
void update(int S,int val){ 
    if(val>dp[S].fi){ 
        dp[S].se=dp[S].fi;
        dp[S].fi=val;
    }else if(val>dp[S].se)
        dp[S].se=val;
}
void init(){ 
    for(int i=1;i<=n;++i)update(a[i],i);
    for(int i=0;i<=20;++i){ 
        for(int j=2e6;j>=0;--j){ 
            if(j&(1<<i)){ 
                update(j^(1<<i),dp[j].fi);
                update(j^(1<<i),dp[j].se);
            }
        }
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    init();
    int ans=0;
    for(int i=1;i<=n-2;++i){ 
        int now=0;
        for(int j=20;j>=0;--j){ 
            if(a[i]&(1<<j))continue;
            if(dp[now^(1<<j)].se>i)now^=(1<<j);
        }
        ans=max(ans,now|a[i]);
    }
    cout<<ans;
    return 0;
}

