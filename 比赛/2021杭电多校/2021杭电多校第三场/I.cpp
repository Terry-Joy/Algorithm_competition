#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=105;
/*
int randnumber( int R) {
        static mt19937 rnd(time(0));
        int res = (int)((1.0 * rnd() / UINT_MAX) * (R + 1)) ;
        return res;
}
bool is(int a,int b,int a1,int b1){ 
    int nxta=randnumber(100000),nxtb=randnumber(100000);
    ll x1=1ll*a*b+1ll*a*nxtb+1ll*b*nxta;
    ll x2=1ll*a1*b1+1ll*a1*nxtb+1ll*b1*nxta;
    return x2>x1;
}*/
struct Node{ 
    int a,b;
    bool operator>(const Node&x){ 
        return (ll)a*b+a+b>(ll)x.a*x.b+x.a+x.b;
    }   
    bool operator<(const Node&x){ 
        return (ll)a*b+a+b>(ll)x.a*x.b+x.a+x.b;
    }
};
vector<Node>dp[maxn][maxn];
int a[maxn][maxn],b[maxn][maxn],n,t;
ll solve(){ 
    dp[1][1].clear();
    dp[1][1].pb({a[1][1],b[1][1]});
    for(int i=1;i<=n;++i){ 
        for(int j=1;j<=n;++j){ 
            int num=0;
            if(i==1&&j==1)continue;
            int x1=0,x2=0,len1=dp[i-1][j].size(),len2=dp[i][j-1].size();
            dp[i][j].clear();
            while(num<100&&(x1<len1||x2<len2)){ 
                if(x1<len1&&x2<len2){
                    Node x=(dp[i-1][j][x1]>dp[i][j-1][x2]?dp[i-1][j][x1++]:dp[i][j-1][x2++]);
                    dp[i][j].pb(x);
                }else if(x1<len1)
                    dp[i][j].pb(dp[i-1][j][x1++]);
                else
                    dp[i][j].pb(dp[i][j-1][x2++]);
                num++;
            }
            for(auto&v:dp[i][j])
                v.a+=a[i][j],v.b+=b[i][j];
            sort(dp[i][j].begin(),dp[i][j].end());
        }
    }
    ll ans=0;
    for(auto&v:dp[n][n])
        ans=max(ans,1ll*v.a*v.b);
    return ans;
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&b[i][j]);
        cout<<solve()<<"\n";
    }
    return 0;
}
