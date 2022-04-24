#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int n,x,y,z,dp[42][(1<<17)+10];
bool is(int bit){ 
    if(!((bit>>(z-1))&1))return 0;
    if(!((bit>>(z+y-1))&1))return 0;
    if(!((bit>>(x+y+z-1))&1))return 0;
    return 1;
}
int Sub(int x,int y){ 
    x-=y;
    if(x<0)x+=mod;
    return x;
}
int Add(int x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y>>z;
    dp[0][0]=1;
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<(1<<(x+y+z));++j){ 
            for(int k=1;k<=10;++k){ 
                int nxt=(j<<k)+(1<<(k-1));
                nxt&=(1<<(x+y+z))-1;
                if(is(nxt))continue;
                dp[i][nxt]=Add(dp[i][nxt],dp[i-1][j]);
            }
        }
    }
    int ans=mypow(10,n);
    for(int i=0;i<(1<<(x+y+z));++i)
        ans=Sub(ans,dp[n][i]);
    cout<<ans<<"\n";
    return 0;
}
