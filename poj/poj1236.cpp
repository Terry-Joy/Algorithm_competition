#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=110,M=10010;
int head[N],next1[M],ver[M],tot,dfn[N],low[N],top,stack[N],cnt,vis[N],num;
int deg[N],c[N],out[N];
vector<int>scc[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stack[++top]=x,vis[x]=1;
    for(int i=head[x];i;i=next1[i])
    {
       int y=ver[i];
       if(!dfn[y])
       {
          tarjan(y);
          low[x]=min(low[x],low[y]); 
       } 
       else if(vis[y])
           low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
       {
          cnt++;int z;
          do{ 
            z=stack[top--];vis[z]=0;
            c[z]=cnt,scc[cnt].push_back(z);
          }while(z!=x);
       }
}
int main()
{
    int n;
    scanf("%d",&n);
	for(int i=1;i<=n;++i)
    {
       int a;
       while(1)
       {
       	  scanf("%d",&a);
       	  if(a==0)
       	  	break;
       	  else add(i,a); 
	   }
    }
    for(int i=1;i<=n;++i)
        if(!dfn[i])tarjan(i);
    int sum=0;
    for(int x=1;x<=n;++x)
    {
       for(int i=head[x];i;i=next1[i]) 
        {
           int y=ver[i];
           if(c[x]==c[y])continue;
           deg[c[y]]++;
           out[c[x]]++;
        }
    }
    int ans=0;
    int k=0;
    for(int i=1;i<=cnt;++i)
    { 
        if(!deg[i])
          ans++;
        if(!out[i])
          k++;
    }
    printf("%d\n",ans);
    if(cnt==1)printf("0\n");
    else
    printf("%d\n",max(k,ans));
}
