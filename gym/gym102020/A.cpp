#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define pb push_back
using namespace std;
typedef long long ll;

ll dp[10002][102][10];
const ll mod=1e9+7;
vector<int>G[12];
int n,m,k,sum[105];
void init()
{ 
    memset(dp,-1,sizeof(dp));
    G[1].pb(8);G[1].pb(6);
    G[2].pb(7);G[2].pb(9);
    G[3].pb(4);G[3].pb(8);
    G[4].pb(3);G[4].pb(9);G[4].pb(0);
    G[6].pb(1);G[6].pb(7);G[6].pb(0);
    G[7].pb(2);G[7].pb(6);
    G[8].pb(1);G[8].pb(3);
    G[9].pb(4);G[9].pb(2);
    G[0].pb(4);G[0].pb(6);
}
ll dfs(int pos,int len,int k)
{
    if(len==m&&m!=0)return 0;
    if(pos==n)return 1;
    if(dp[pos][len][k]!=-1)return dp[pos][len][k];
    ll ans=0;
    for(int i=0;i<G[k].size();++i)
    {
        int t=len;
        if(G[k][i]==sum[len])t=len+1;
        else if(G[k][i]==sum[0])t=1;
        else t=0;
        ans+=dfs(pos+1,t,G[k][i]);//第一次失配的时候可能转到第一个能匹配的地方
        ans%=mod;//防止中间越界
    } 
     dp[pos][len][k]=ans;
    return ans;
}
int main()
{
   init();
   scanf("%d%d%d",&n,&m,&k);
   getchar();//读走换行
   for(int i=0;i<m;++i)
       sum[i]=getchar()-'0';
   ll ans=0;
   for(int i=0;i<G[k].size();++i)
   {
      ans+=dfs(1,(G[k][i]==sum[0])?1:0,G[k][i]);
      ans%=mod; 
   }
   printf("%lld",ans);
   return 0; 
}
