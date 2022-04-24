#include<bits/stdc++.h>

using namespace std;
int dp[105][155];
struct Node{
    int t,f,h;
    bool operator<(const Node&a)const{
        return t<a.t;
    }
}node[105];
int d,g;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>d>>g;
    for(int i=1;i<=g;++i)cin>>node[i].t>>node[i].f>>node[i].h;
    sort(node+1,node+1+g);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=10;
    node[0].t=0;
    int ans=10;
    for(int i=1;i<=g;++i){
        for(int j=0;j<=d;++j){
            if(dp[i-1][j]==-1)continue;
            if(dp[i-1][j]<node[i].t-node[i-1].t)continue;
            if(j+node[i].h>=d){
                cout<<node[i].t;return 0;
            }
            dp[i][j+node[i].h]=max(dp[i][j+node[i].h],dp[i-1][j]-(node[i].t-node[i-1].t));
            dp[i][j]=max(dp[i][j],dp[i-1][j]-(node[i].t-node[i-1].t)+node[i].f);
        }
        if(dp[i][0]!=-1)
            ans=max(ans,dp[i][0]+node[i].t);
    }
    cout<<ans;
    return 0;
}