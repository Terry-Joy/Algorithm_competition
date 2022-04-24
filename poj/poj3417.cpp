#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+100,M=2e5+100;
int head[N],next1[M],ver[M],tot,f[N][22],d[N],temp[N],num[N],k,lg[N];
int n,m;
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
    num[++k]=now;
    f[now][0]=fa,d[now]=d[fa]+1;
    for(int i=head[now];i;i=next1[i])
    {
       if(ver[i]!=fa)
       {
           dfs(ver[i],now);
       } 
    }
}
void init()
{
   for(int i=1;i<=lg[n];++i)
        for(int j=1;j<=n;++j)
           f[j][i]=f[f[j][i-1]][i-1]; 
}
int lca(int x,int y)
{
    if(d[x]>d[y])
        swap(x,y);
    for(int i=lg[d[y]];i>=0;--i)
    {
        if(d[f[y][i]]>=d[x])
            y=f[y][i];
    }
    if(x==y)return x;
    for(int i=lg[d[x]];i>=0;--i)
    {
       if(f[y][i]!=f[x][i])
          y=f[y][i],x=f[x][i]; 
    }
    return f[x][0];
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=2;i<=n;++i)
   		lg[i]=lg[i>>1]+1;
   for(int i=1;i<n;++i)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      add(a,b);
      add(b,a); 
   }
   dfs(1,0);
   init(); 
   for(int i=1;i<=m;++i)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      temp[a]++,temp[b]++,temp[lca(a,b)]-=2; 
   }
   for(int i=n;i>=1;--i)temp[f[num[i]][0]]+=temp[num[i]];
   int ans=0;
   for(int i=2;i<=n;++i)
   {
      if(temp[i]==0)
         ans+=m;
      else if(temp[i]==1)
         ans++; 
   }
    printf("%d\n",ans);
    return 0;
}
