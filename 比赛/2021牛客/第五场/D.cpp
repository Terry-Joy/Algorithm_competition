#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+3;
const int mod=1e9+7;
int dp[maxn][maxn],fac[(maxn<<1)+2],facinv[(maxn<<1)+2];
char s1[maxn],s2[maxn];
int mypow(int a,int b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){ 
    fac[1]=fac[0]=1;
    for(int i=2;i<(maxn<<1);++i)fac[i]=(ll)fac[i-1]*i%mod;
    facinv[(maxn<<1)-1]=mypow(fac[(maxn<<1)-1],mod-2);
    for(int i=(maxn<<1)-2;i>=0;--i)
        facinv[i]=(ll)facinv[i+1]*(i+1)%mod;
}
int C(int n,int m){ 
    return (ll)fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
void add(int&x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
}
void del(int&x,int y){ 
    x-=y;
    if(x<0)x+=mod;
}
int main(){ 
    init();
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int n=strlen(s1+1),m=strlen(s2+1);
    for(int i=0;i<=m;++i)dp[0][i]=1;
    for(int i=0;i<=n;++i)dp[i][0]=1;
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            add(dp[i][j],dp[i-1][j]+dp[i][j-1]);
            del(dp[i][j],dp[i-1][j-1]);
            if(s1[i]==s2[j])           
               add(dp[i][j],dp[i-1][j-1]); 
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=m;++j){ 
            if(s1[i]<s2[j]){ 
                add(ans,(ll)dp[i-1][j-1]*C(n-i+m-j,min(n-i,m-j))%mod);
            }
        }
    }
    cout<<ans;
    return 0;
}
