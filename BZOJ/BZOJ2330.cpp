#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
using namespace std;

const int N=1e5+10,M=4e5+100;
int head[N],ver[M],edge[M],tot,d[N],cnt[N],next1[M],n,k,dfn[N],low[N],cnt,stack[N],top,c[N];
bool vis[N];
int num;
vector<int>scc[N];

void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}

void tarjan(int x)
{
   dfn[x]=low[x]=++num;
   stack[++top]=x,v[x]=1;
   for(int i=head[x];i;i=next[i])
   {
      int y=ver[i],z=edge[i];
      if(z)continue;
      if(!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]); 
      }
      else  if(vis[y])
          low[x]=min(low[x],dfn[y]);
   }
  if(low[x]==dfn[x])
  {
     cnt++;int k;
     do{ 
        k=stack[top--];vis[k]=0;
        scc[cnt].push_back(k);c[k]=cnt;
     }while(k!=x); 
  } 
}

int main()
{
    scanf("%d%d",&n,&k);
    int x,a,b;
    for(int i=1;i<=k;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if((a==2||a==4)&&b==c)
        {
           puts("-1");
           return 0; 
        }
        switch(a)
        {
            case 1:add(b,c,0),add(c,b,0);break;
            case 2:add(b,c,1);break;
            case 3:add(c,b,0);break;
            case 4:add(c,b,1);break;
            case 5:add(b,c,0);break; 
        }
    }
    for(int i=n;i>0;--i)add(0,i,1);
    for(int i=0;i<=n;++i)
        if(!dfn[i])tarjan(i);
    
    if(!spfa())
    {
        puts("-1");
        return 0;
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
        ans+=d[i];
    printf("%lld",ans);
    return 0;
}

