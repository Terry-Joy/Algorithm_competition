#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[10010][3];//dp[i][0]表示自己没建塔，自己儿子全覆盖 自己没覆盖
//dp[i][1]表示自己没建塔 自己和儿子都覆盖
//dp[i][2]表示自己建塔 自己和儿子都覆盖
vector<int>G[10010];
const int maxn=0x3f3f3f3f;
void dfs(int now,int fa)
{
   if(G[now].size()==1&&G[now][0]==fa)
   {
      dp[now][0]=0;
      dp[now][1]=maxn;
      dp[now][2]=1; 
      return;
   } 
   int flag=1,min1=maxn;
   for(int i=0;i<G[now].size();++i)
   {
      int y=G[now][i];
      if(y!=fa)
      {
         dfs(y,now);
         dp[now][0]+=min(dp[y][1],dp[y][2]);
         dp[now][2]+=min(min(dp[y][1],dp[y][2]),dp[y][0]);
         if(dp[y][1]<dp[y][2])
         {
            dp[now][1]+=dp[y][1];
            min1=min(min1,dp[y][2]-dp[y][1]);   //记录子节点全都不放时差的最小值 
         } 
         else
         {
            flag=0;
            dp[now][1]+=dp[y][2]; 
         }
      } 
   }
   dp[now][2]++;
   if(flag)                             //子节点必须放一个且保证增加最小
       dp[now][1]+=min1;
}
int main()
{ 
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;++i)
        G[i].clear();
    for(int i=1;i<n;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       G[a].push_back(b);
       G[b].push_back(a); 
    }
    dfs(1,0);
    printf("%d\n",min(dp[1][1],dp[1][2]));
    return 0;
}
