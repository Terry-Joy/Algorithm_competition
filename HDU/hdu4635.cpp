#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;

const int N=1e5+10,M=1e5+10,INF=0x3f3f3f3f;
int head[N],ver[M],next1[M],tot,dfn[N],low[N],num,cnt,stack[N],top,c[N],in[N],out[N],sum[N];
bool vis[N];

void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

void tarjan(int x)
{
   dfn[x]=low[x]=++num;
   stack[++top]=x;vis[x]=1;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[y],low[x]); 
      } 
      else if(vis[y])
          low[x]=min(low[x],dfn[y]);
   } 
   if(low[x]==dfn[x])
   {
      ++cnt;int z;
      do{
        sum[cnt]++; 
        z=stack[top--];vis[z]=0;
        c[z]=cnt;
      }while(z!=x); 
   }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
       int n,m;
       scanf("%d%d",&n,&m);
       tot=num=top=cnt=0;
       for(int i=1;i<=n;++i)
          head[i]=dfn[i]=low[i]=c[i]=0;
       for(int i=1;i<=m;++i)
       {
          int a,b;
          scanf("%d%d",&a,&b);
          add(a,b); 
       } 
       for(int i=1;i<=n;++i)
           if(!dfn[i])tarjan(i);
       if(cnt==1)
       {
          printf("Case %d: -1\n",i);
          continue; 
       }
       for(int x=1;x<=n;++x)
          for(int j=head[x];j;j=next1[j])
            {
               int y=ver[j];
               if(c[x]==c[y])continue;
               out[c[x]]++,in[c[y]]++; 
            }
       int ans=INF;
       for(int i=1;i<=cnt;++i)
           if(out[i]==0||in[i]==0)
               ans=min(ans,sum[i]);
       printf("Case %d: %lld\n",i,(ll)n*(n-1)-(ll)ans*(n-ans)-m);
       for(int i=1;i<=cnt;++i)
           sum[i]=in[i]=out[i]=0;
    }
    return 0;
}
