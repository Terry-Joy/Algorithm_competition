#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=110;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int Max[MAXN][MAXN];    //Max[i][j]表示MST中从i到j的最大边权 //返回-1表示原图不连通
//若x不在MST中，lowc[x]表示x与MST中的节点之间权值最小的边的权值，否则表示入树时选出的最小边的权值
//used[x][y]表示x到y是否中最小生成树中这条边有没有被用到
bool used[MAXN][MAXN];
int cost[MAXN][MAXN],ans=0;
int prim(int cost[][MAXN],int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    memset(Max,0,sizeof(Max));
    memset(used,0,sizeof(used));
    vis[0]=1;                   //0`(n-1)
    pre[0]=-1;
    for(int i=1;i<n;++i)
    {
       lowc[i]=cost[0][i];
       pre[i]=0; 
    }
    lowc[0]=0;
    for(int i=1;i<n;++i)
    {
       int minc=INF;
       int p=-1;
       for(int j=0;j<n;++j)
          if(!vis[j]&&lowc[j]<minc)
          {
             minc=lowc[j];
             p=j; 
          } 
       if(minc==INF)return -1;          //图不连通
       vis[p]=true;
       ans+=minc;
       used[p][pre[p]]=used[pre[p]][p]=true;        //标记已经进入了MST
       for(int j=0;j<n;++j)
        {
           if(vis[j])Max[j][p]=Max[p][j]=max(Max[j][pre[p]],lowc[p]);       //dp更新MST中p到j最大边权
           if(!vis[j]&&lowc[j]>cost[p][j])                              
           {
              lowc[j]=cost[p][j];                   //记录
              pre[j]=p;                             //记录前驱节点
           } 
        }
    }
    return ans;
}
int smst(int cost[][MAXN],int n)
{
   int Min=INF;
   for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
          if(cost[i][j]!=INF&&!used[i][j])              //在剩下的没有被用过的边中替换再计算总和
      { 
          Min=min(Min,ans+cost[i][j]-Max[i][j]);
      } 
      if(Min==INF)return -1;                            //图不连通
      return Min;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&m);
       int a,b,c;
       for(int i=0;i<n;++i)
          for(int j=0;j<n;++j)
          {
             if(i==j)cost[i][j]=0;
             else cost[i][j]=INF; 
          } 
       while(m--)
       {
          scanf("%d%d%d",&a,&b,&c);
          a--;b--;
          cost[a][b]=cost[b][a]=c;
       }
       ans=prim(cost,n);
       if(ans==-1)
       {
          puts("Not Unique!");
          continue; 
       }
       if(ans==smst(cost,n))puts("Not Unique!");
       else printf("%d\n",ans);
    }
    return 0;
}
