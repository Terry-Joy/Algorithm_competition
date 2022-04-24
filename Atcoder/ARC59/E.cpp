#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=405;
const int mod=1e9+7;
int n,c,a[maxn],b[maxn],dp[maxn][maxn],p[maxn][maxn],sum[maxn][maxn],num[maxn];
int Add(int x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int mul(int x,int y){ 
    return (ll)x*y%mod;
}
int Sub(int x,int y){ 
    x-=y;
    if(x<0)x+=mod;
    return x;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=400;++i){ 
        p[i][0]=1;
        for(int j=1;j<=400;++j){ 
            p[i][j]=mul(p[i][j-1],i);
        }
    }
    cin>>n>>c;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=0;i<=400;++i){ 
        sum[1][i]=1;
        for(int j=2;j<=400;++j){ 
            sum[j][i]=Add(sum[j-1][i],p[j][i]);
        }
    }   
    dp[0][0]=1;
    for(int i=0;i<n;++i){ 
        for(int j=0;j<=c;++j){ 
            for(int k=0;k+j<=c;++k){ 
                dp[i+1][k+j]=Add(dp[i+1][k+j],mul(dp[i][j],Sub(sum[b[i+1]][k],sum[a[i+1]-1][k])));
            }
        }
    }
    cout<<dp[n][c];
    return 0;
}
