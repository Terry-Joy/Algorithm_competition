#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int c[310][310],vis[310],d[310];
const int INF=0x3f3f3f3f;
    int n;
void spfa(int u)
{ 
    queue<int>q;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i)
    {
        if(i==u)
            d[i]=INF;        //找自环
        else
        {
           d[i]=c[u][i];
           q.push(i);
           vis[i]=1; 
        }
    }
    while(q.size())
    {
       int t=q.front();
       q.pop();
       vis[t]=0;
       for(int i=1;i<=n;++i)
       {
          if(d[i]>d[t]+c[t][i]){ 
            d[i]=d[t]+c[t][i];
            if(!vis[i]){ 
                vis[i]=1;
                q.push(i);
            }
          } 
       } 
    }
}
int main()
{
    while(~scanf("%d",&n)){ 
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&c[i][j]);
    spfa(1);
    int ans=d[n];
    int d1=d[1];
    spfa(n);
    int d2=d[n]; 
    printf("%d\n",min(ans,d1+d2));
    }
    return 0;
}
