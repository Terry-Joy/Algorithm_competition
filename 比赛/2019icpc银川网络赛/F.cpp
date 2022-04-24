#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int maxn=205;
typedef pair<int,int>P;
int n,T,q,d[maxn][maxn],dp[maxn][maxn][maxn];
struct Node{ 
    int r,id;
    bool operator<(const Node&x)const{ 
        return r<x.r;
    }
}a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=0,t;
    cin>>t;
    while(t--){ 
        cin>>n>>q;
        for(int i=1;i<=n;++i){ 
            cin>>a[i].r;a[i].id=i;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)cin>>dp[0][i][j];
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)dp[i][j][k]=2e9;
        for(int k=1;k<=n;++k){ 
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    dp[k][i][j]=min(dp[k-1][i][j],dp[k-1][i][a[k].id]+dp[k-1][a[k].id][j]);
        }
        cout<<"Case #"<<++T<<":\n";
        for(int i=1;i<=q;++i){ 
            int u,v,w;
            cin>>u>>v>>w;
            int ans=2e9,j;
            for(j=1;j<=n;++j){ 
                if(a[j].r>w)break;
            }
            cout<<dp[j-1][u][v]<<"\n";
        }
    } 
    return 0;
}
