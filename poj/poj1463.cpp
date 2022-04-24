#include<iostream>
#include<cstdio>
using namespace std;
const int N=1510;
int head[N],ver[3010],next1[3010],tot,dp[N][2],v[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
       if(ver[i]!=fa)
       {
          dfs(ver[i],now);
          dp[now][1]+=min(dp[ver[i]][1],dp[ver[i]][0]);
          dp[now][0]+=dp[ver[i]][1]; 
       } 
    }
}
int main()
{
   int n;
   while(scanf("%d",&n)!=EOF)
   {
   	  char ch;
      int root,ed,node;
      tot=0;
      for(int i=0;i<=n;++i)
          dp[i][1]=1,dp[i][0]=0,head[i]=0;
      for(int i=1;i<=n;++i)
      {
         scanf("%d:(%d)",&root,&ed);
         for(int j=1;j<=ed;++j)
         {
            scanf("%d",&node);
            add(root,node);
            add(node,root); 
         } 
      }
      dfs(0,0);
      int ans=min(dp[0][0],dp[0][1]);
      printf("%d\n",ans);
   } 
   return 0;
}
