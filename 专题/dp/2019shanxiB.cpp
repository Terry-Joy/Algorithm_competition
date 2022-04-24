#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=205;
vector<int>G[N];
const int maxn=5e4+5;
int dp[N][maxn],val[2][N],w[N],t,n,m,sum,cnt=0,num1,num2,sum2=0;
bool vis[N],col[N];
void dfs(int x){
    vis[x]=1;
    for(auto&y:G[x]){
        if(!vis[y]){
            col[y]=col[x]^1;
            if(!col[y])num1+=w[y];
            else num2+=w[y];
            dfs(y);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int x,y;
    while(t--){
        memset(vis,0,sizeof(vis));  
        sum=cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>w[i],sum+=w[i],G[i].clear();
        sum2=sum;
        sum2/=100; 
        for(int i=1;i<=m;++i){
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        sum/=200;
        for(int i=1;i<=n;++i){
            if(!vis[i]){
                num1=w[i],num2=0;
                col[i]=0;
                dfs(i);
                val[0][++cnt]=num1/100;
                val[1][cnt]=num2/100;
            }
        }
        for(int i=1;i<=cnt;++i){
            int w1=val[0][i],w2=val[1][i];
            for(int j=0;j<=sum;++j){
                if(j>=w1)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-w1]+w1);
                if(j>=w2)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-w2]+w2);
            }
        }
        printf("%d\n",(sum2-dp[cnt][sum])*100);
    }
    return 0;
}