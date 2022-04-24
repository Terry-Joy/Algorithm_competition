#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=10010,M=1010;
int a[N],d[N][M],n,m,g,r; //d[i][j]到第i个点时候，绿灯已经过了j秒，经过多少次红绿灯变换
//01bfs,以红绿灯的轮数作为边的权值，0的丢前面，1的丢后面·
bool vis[N][M];
struct Node
{
   int pos,t; 
};
ll bfs()
{
    deque<Node>q;
    q.push_back({0,0});
    ll ans=-1;
    vis[0][0]=1;
    while(q.size())
    {
       Node now=q.front();
       q.pop_front();
       if(now.t==0)//刚等完红灯
       {
          int res=n-a[now.pos];
          if(res<=g)
          {
             ll x=1ll*d[now.pos][0]*(g+r)+res;
             if(ans==-1||ans>x)
                 ans=x;
          } 
       } 
       if(now.t==g)//需要到红灯
       {
          if(!vis[now.pos][0])  //当前的安全岛没被访问过
          {
             d[now.pos][0]=d[now.pos][now.t]+1;
             vis[now.pos][0]=1;
             q.push_back({now.pos,0}); 
          } 
          continue;
       }
       //序号大于1
       if(now.pos>1)
       {
          int p=now.pos-1;//往前走
          int t=now.t+a[now.pos]-a[p];//回去的时候绿灯是多少了
          if(t<=g&&!vis[p][t])//没回去过且能走到
          {
              vis[p][t]=1;
              d[p][t]=d[now.pos][now.t];//红绿灯轮数不变
              q.push_front({p,t});
          }
       }
       if(now.pos<m)//往后走
       {
          int p=now.pos+1;
          int t=now.t+a[p]-a[now.pos];
          if(t<=g&&!vis[p][t])
          {
             vis[p][t]=1;
             d[p][t]=d[now.pos][now.t];
             q.push_front({p,t}); 
          } 
       }
    }
    return ans;
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;++i)
       scanf("%d",&a[i]);
   scanf("%d%d",&g,&r);
   sort(a+1,a+1+m);
   printf("%d\n",bfs());
   return 0; 
}
