#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N=17,M=10000;
int head[N],next1[M],ver[M],tot,r[N][N],c[N][N],n,match[N];
char s[N][N];
bool vis[N*N];
bool  dfs(int x)
{
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!vis[y])
      {
         vis[y]=1;
         if(!match[y]||dfs(match[y]))
            {
                match[y]=x;return true;
            } 
      } 
   } 
   return false;
}
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

int main()
{
    int i,j;
    while(~scanf("%d",&n)&&n)
    {
        tot=0;
        memset(head,0,sizeof(head));
        memset(match,0,sizeof(match));
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        int s1=0,s2=0;
        for(i=1;i<=n;++i)
            scanf("%s",s[i]+1);
        for(i=1;i<=n;++i)
        {
           for(j=1;j<=n;++j)
           {
              if(s[i][j]=='.')
              {
                 ++s1;
                 while(s[i][j]=='.'&&j<=n)
                 {
                     r[i][j]=s1;j++;
                 }
              } 
           } 
        }
        for(i=1;i<=n;++i)
        {
           for(j=1;j<=n;++j)
            {
               if(s[j][i]=='.')
               { 
                   ++s2;
                   while(s[j][i]=='.'&&j<=n)
                   {
                      c[j][i]=s2;j++; 
                   }
               } 
            } 
        }
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
               if(s[i][j]!='X')
                  add(r[i][j],c[i][j]); 
            }
        int ans=0;
        for(i=1;i<=s1;++i)
        {
           for(j=1;j<=s2;++j)
              vis[j]=0;
           if(dfs(i))ans++; 
        }
        printf("%d\n",ans);
    }    
    return 0;
}

