#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1010;
const int mod=1e9+7;
ll dp[maxn];
char x,y,z,f;
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    dp[0]=dp[1]=1;
    cin>>n>>x>>y>>z>>f;
  	if(n==2){cout<<"1"<<endl;return 0;}
    for(int i=2;i<=n+5;++i){ 
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    } 
    ll ans=0;
    if(y=='A'){ 
        if(x=='A')ans=1;
        else if(x=='B'&&z=='A')ans=dp[n-2];
        else if(x=='B'&&z=='B')ans=mypow(2,n-3);
    }else if(y=='B'){ 
        if(f=='B')ans=1;
        else if(f=='A'&&z=='B')ans=dp[n-2];
        else if(f=='A'&&z=='A')ans=mypow(2,n-3);
    }
    cout<<ans;
    return 0;
}
