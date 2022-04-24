#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=3010;
struct Node{ 
    double x,y,s;
}a[N],b[N];
bool map[N][N];
bool vis[N];
int dx[N],dy[N];//dx[i]表示左集合i顶点的距离编号，dy[i]表示右集合i顶点的距离编号，对于bfs找增广路用的数组，对于u->v有dy[v]=dx[u]+1;
int cx[N],cy[N];
int dis,n,t,m;
bool searchpath()
{
   queue<int>q;
   dis=INF;
   memset(dx,-1,sizeof(dx));
   memset(dy,-1,sizeof(dy));
   for(int i=1;i<=n;++i)
   {  //cx[i]表示左集合i顶点所匹配的右集合的顶点序号
      if(cx[i]==-1)
      {//将未遍历的节点入队，并初始化次节点距离为0
         q.push(i);
         dx[i]=0; 
      } 
   } 
   //广度搜索增广路径
   while(!q.empty())
   {
      int u=q.front();
      q.pop();
      if(dx[u]>dis)break;
      //取右侧节点，用m
      for(int v=1;v<=m;++v)
      {
         if(map[u][v]&&dy[u]==-1)
         {
            dy[v]=dx[u]+1//v对应的距离 为u对应距离+1
            if(cy[v]==-1)dis=dy[v];
            else
            {
               dx[cy[v]]=dy[v]+1;
               q.push(cy[v]); 
            } 
         } 
      } 
   }
   return dis!=INF;
}
bool dfs(int u)
{
   for(int v=1;v<=m;++v)
   {//如果该点没有被遍历过，并且距离为上一节点+1
       if(map[u][v]&&!vis[v]&&dy[v]==dx[u]+1)
       {
          //染色
          vis[v]=1;
          if(cy[v]!=-1&&dy[v]==dis)continue;
          if(cy[v]==-1||dfs(cy[v]))
          {
             cx[u]=v;
             cy[v]=u;
             return true;
          }
       }
   } 
   return false;
}
