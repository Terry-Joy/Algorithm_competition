#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=25;
const int mod=998244353;
int n;
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
int ans[maxn][maxn],dp[(1<<20)+20],a[maxn][maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j)cin>>a[i][j];
    }
    dp[0]=1;
    for(int i=0;i<(1<<n)-1;++i){ 
        int num=__builtin_popcount(i),sum=0;
        for(int j=0;j<n;++j){ 
            if(i&(1<<j))continue;
            sum+=a[num][j];
        }
        sum=mypow(sum,mod-2);
        for(int j=0;j<n;++j){ 
            if(i&(1<<j))continue;
            int p=mul(dp[i],mul(a[num][j],sum));
            dp[i|(1<<j)]=Add(dp[i|(1<<j)],p);
            ans[num][j]=Add(ans[num][j],p);
        }
    }
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j){
            if(j!=n-1)
                cout<<ans[i][j]<<" ";
            else
                cout<<ans[i][j]<<"\n";
        }
    }
    return 0;
}
