#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+10,M=1e6+5;
int head[N],ver[M],next1[M],size[N],tot,sum,low[N],dfn[N],num,n,m;
bool cnt[N];
ll ans[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void tarjan(int x)
{
    int flag=0,sum=0;
    dfn[x]=low[x]=++num;
    for(int i=head[x];i;i=next1[i])
    {
       int y=ver[i];
       if(!dfn[y])
       {
          tarjan(y);
          size[x]+=size[y];
          low[x]=min(low[x],low[y]);
          if(dfn[x]<=low[y])
          { 
              flag++;
              ans[x]+=(ll)size[y]*(n-size[y]);
              sum+=size[y];
              if(x!=1||flag>1)cnt[x]=1;
          } 
       } 
       else low[x]=min(low[x],dfn[y]);
    }
    if(cnt[x])
        ans[x]+=(ll)(n-sum-1)*(sum+1)+(n-1);
    else
        ans[x]=2*(n-1);
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       add(a,b);add(b,a);
    } 
    for(int i=1;i<=n;++i)
        size[i]=1;
    tarjan(1);
    for(int i=1;i<=n;++i)
        printf("%lld\n",ans[i]);
    return 0;
}