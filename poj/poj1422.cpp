#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=250,maxm=250*250;
int head[maxn],ver[maxm],next1[maxm],tot,match[maxn],n,m;
bool vis[maxn];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

bool dfs(int x)
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

int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    while(t--)
    {
        tot=0;
        memset(head,0,sizeof(head));
        memset(match,0,sizeof(match));
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;++i)
        {
           scanf("%d%d",&a,&b);
           add(a,b); 
        }
        int ans=0;
        for(i=1;i<=n;++i)
        {
           memset(vis,0,sizeof(vis));
           if(dfs(i))ans++; 
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
