#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5005;
const int mod=1e9+7;
int n,dp[maxn][maxn];
char s[maxn];
int Add(int x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int mul(int x,int y){ 
    return (ll)x*y%mod;
}
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    cin>>(s+1);
    int len=strlen(s+1);
    dp[0][0]=1;
    for(int i=0;i<n;++i){ 
        for(int j=0;j<=i;++j){ 
            dp[i+1][j+1]=Add(dp[i+1][j+1],mul(2,dp[i][j]));
            dp[i+1][max(j-1,0)]=Add(dp[i+1][max(j-1,0)],dp[i][j]);
        }
    }
    cout<<mul(dp[n][len],mypow(mypow(2,len),mod-2));
    return 0;
}
