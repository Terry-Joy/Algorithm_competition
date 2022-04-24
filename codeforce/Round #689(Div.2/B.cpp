#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char a[505][505];
ll dp[505][505];
int n,m;
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){ 
                cin>>a[i][j];
                if(a[i][j]=='*')dp[i][j]=1;
            }
        for(int i=n-1;i>=1;--i)
            for(int j=1;j<=m;++j){ 
                if(dp[i][j])
                dp[i][j]=min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))+1;
            }
        ll ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){ 
                if(a[i][j]=='*')
                ans+=dp[i][j];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
