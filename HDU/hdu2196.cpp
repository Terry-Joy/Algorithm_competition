#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e4+10,M=2e4+10;
int head[N],ver[M],edge[M],next1[M],n,d[N],s,max_len,tot;
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa,int len)
{
   if(max_len<=len)
   {
      s=now,max_len=len; 
   } 
   for(int i=head[now];i;i=next1[i])
   {
      if(ver[i]!=fa)
      {
         dfs(ver[i],now,len+edge[i]);
         d[ver[i]]=max(d[ver[i]],len+edge[i]); 
      } 
   }
}
int main()
{
    while(~scanf("%d",&n))
    {
        tot=0;
        for(int i=0;i<=n;++i)
            head[i]=0;
        memset(d,0,sizeof(d));
        for(int i=2;i<=n;++i)
        {
           int a,b;
           scanf("%d%d",&a,&b);
           add(i,a,b);
           add(a,i,b); 
        }
        s=0,max_len=0;
        dfs(1,0,0);
        dfs(s,0,0);
        dfs(s,0,0);
        for(int i=1;i<=n;++i)
            printf("%d\n",d[i]);
    } 
  return 0;  
}
