#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=2e4+10,M=1e6+10;
int head[N],ver[M<<2],next1[M<<2],low[N],dfn[N],cnt=-1,stack[N],top,num,c[N],vis[N],tot;
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stack[++top]=x;
    vis[x]=1;
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
    if(low[x]==dfn[x])
    {
       int z;
       cnt++;
       do{ 
          z=stack[top--];vis[z]=0;
          c[z]=cnt;
       }while(z!=x); 
    }
}
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;++i)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      char s[6];
      scanf("%s",s);
      if(s[0]=='A')
      {
         if(c==1)
         {
            add(a,a+n);
            add(b,b+n); 
         } 
         else
         {
            add(a+n,b);
            add(b+n,a); 
         }
      }
      else if(s[0]=='O')
      {
         if(c==1)
         {
            add(a,b+n);
            add(b,a+n); 
         } 
         else
         {
            add(a+n,a);
            add(b+n,b); 
         }
      }
      else if(s[0]=='X')
      {
         if(c==1)
         {
            add(a,b+n);
            add(a+n,b);
            add(b+n,a);
            add(b,a+n); 
         } 
         else 
         {
            add(a,b);
            add(a+n,b+n);
            add(b,a);
            add(b+n,a+n); 
         }
      }
   }  
   for(int i=0;i<2*n;++i)
       if(!dfn[i])tarjan(i);
   int flag=1;
   for(int i=0;i<n;++i)
   {
      if(c[i]==c[i+n])
        {
            puts("NO");
            return 0;
        }
   }
   puts("YES");
   return 0; 
}
