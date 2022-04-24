#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define pb push_back 
using namespace std;
const int INF=0x3f3f3f3f;
int dp[12][1<<10];
struct Node{ 
    int b,c,p,r;
}edge;
vector<Node>G[15];
int main()
{
   int n,m,ai,bi,ci,pi,ri;
   scanf("%d%d",&n,&m); 
   for(int i=1;i<=m;++i)
   {
      scanf("%d%d%d%d%d",&ai,&edge.b,&edge.c,&edge.p,&edge.r); 
      G[ai].pb(edge);
   }
   memset(dp,INF,sizeof(dp));
   int k=(1<<n)-1;
   dp[1][1]=0;
   for(int s=1;s<=k;++s)
   {
      bool flag=1;          //松弛
      while(flag)           //当无法松弛时才从这个状态退出
      {
         flag=0;
         for(int i=1;i<=n;++i)
         {
            if(!(s&(1<<i-1)))continue;
            for(int j=0;j<G[i].size();++j)      //走过也可以走
            { 
               int v=G[i][j].b,tmp=INF;
               if(s&(1<<(G[i][j].c-1))) 
                   tmp=min(tmp,dp[i][s]+G[i][j].p);
               tmp=min(tmp,dp[i][s]+G[i][j].r);
               if(tmp<dp[v][s|(1<<v-1)])
               {
                  dp[v][s|(1<<v-1)]=tmp;
                  flag=1; 
               }
            }
         } 
      } 
   }
   int ans=INF;
   for(int s=0;s<=k;++s)
       if(s&1)
           ans=min(ans,dp[n][s]);
   if(ans==INF)
       puts("impossible");
   else
       printf("%d\n",ans);
   return 0; 
}
