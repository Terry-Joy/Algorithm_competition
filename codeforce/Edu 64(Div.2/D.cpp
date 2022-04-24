#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot;
ll dp[maxn][4];
ll ans;
//dp[x][0]: x出发的全为0的数目
//dp[x][1]:由x出发的先0后1的路径数目
//dp[x][2]:由x出发先1后0,dp[x][3]全为1

void add(int x,int y,int z)
{
   ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot; 
}
void dfs(int x,int fa)
{
   ll sum[4];
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      int s=edge[i];
      if(ver[i]==fa)continue;
      dfs(y,x);
      if(s==0)//sum是当前子树的贡献
      {
         sum[0]=dp[y][0]+1;
         sum[1]=dp[y][1]+dp[y][3];
         sum[2]=sum[3]=0; 
      } 
      else
      {
         sum[0]=sum[1]=0;
         sum[2]=dp[y][2]+dp[y][0];
         sum[3]=dp[y][3]+1; 
      }
      ans+=(2*sum[0]*dp[x][0]+sum[0]*dp[x][3]+sum[0]*dp[x][1]);
      ans+=(sum[1]*dp[x][0]);
      ans+=sum[2]*dp[x][3];
      ans+=sum[3]*dp[x][0]+sum[3]*dp[x][2]+2*sum[3]*dp[x][3];
      for(int i=0;i<4;++i)			//dp更新
          dp[x][i]+=sum[i];
   } 
   ans+=dp[x][0]*2+dp[x][1]+dp[x][2]+dp[x][3]*2;//在x的一个子树上
}
int main()
{
   int t;
   scanf("%d",&t);
   for(int i=1;i<t;++i)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
      add(b,a,c); 
   }
   dfs(1,0);
   printf("%lld\n",ans);
   return 0; 
}
