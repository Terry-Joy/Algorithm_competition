#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long 
using namespace std;
int head[60],next1[2510*50],ver[2510*50],tot,match[2510];
bool vis[2510];
struct node{ 
    int x,y;
}a[60],b[60];
struct Node{ 
    int x;double y;
}c[2510];
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
             match[y]=x;
             return true; 
          } 
      } 
   } 
   return false;
}
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
double check(int i,int j)
{
   return sqrt((a[i].x-b[j].x)*(a[i].x-b[j].x)*1.0+(a[i].y-b[j].y)*(a[i].y-b[j].y)*1.0);
}
int main()
{
    int n,m,t2,v,i,j,t;
    double t1;
    double l,r,mid;
    scanf("%d%d%lf%d%d",&n,&m,&t1,&t2,&v);
    t=m*n;
    t1/=60;
    for(i=1;i<=m;++i)
        scanf("%d%d",&a[i].x,&a[i].y);
    for(i=1;i<=n;++i)
        scanf("%d%d",&b[i].x,&b[i].y);
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
        {
           c[(i-1)*n+j].x=j;c[(i-1)*n+j].y=i*t1+(i-1)*t2;//每个塔最多分出m个节点,1....n,  n+1....2n 
        }
    l=t1,r=(15000+t1+t2)*50;
    while(l+1e-8<r)
    {
       mid=(l+r)/2;
       memset(head,0,sizeof(head));tot=0;
       memset(match,0,sizeof(match));
       for(i=1;i<=m;++i)
          for(j=1;j<=t;++j)
          {
             if(check(i,c[j].x)/v+c[j].y-mid<1e-8)add(i,j); 
          } 
       for(i=1;i<=m;++i)
       {           
          memset(vis,0,sizeof(vis));
          if(!dfs(i))break;
       }
       if(i>m)
           r=mid;
       else 
           l=mid; 
    }
    printf("%.6lf\n",l);
    return 0;
}
