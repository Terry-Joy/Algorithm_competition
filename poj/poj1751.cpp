#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=750;
int a1[N+100],b1[N+100];
struct Node
{
   int x,y,a,b;
   double ed;
   bool operator<(const Node&a)const
   {
      return ed<a.ed; 
   }
}edge[N*N+100];
int n,m,fa[N+100];
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
       scanf("%d%d",&edge[i].x,&edge[i].y);
    }
    int a,b;
    for(int i=1;i<=n;++i)
        fa[i]=i;
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    { 
        scanf("%d%d",&a,&b);
        int fx=find(a);
        int fy=find(b);
        if(fx==fy)continue;
        fa[fy]=fx;
    }
    int k=0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
        {
           edge[++k].ed=double(edge[i].x-edge[j].x)*(edge[i].x-edge[j].x)+double(edge[i].y-edge[j].y)*(edge[i].y-edge[j].y);
           edge[k].a=i;
           edge[k].b=j;
        }
        sort(edge+1,edge+k+1);
        int len=0;
        for(int i=1;i<=k;++i)
        {
            int fx=find(edge[i].a);
            int fy=find(edge[i].b);
            if(fx==fy)continue;
            fa[fx]=fy;
            a1[++len]=edge[i].a;
            b1[len]=edge[i].b;
        }
        for(int i=1;i<=len;++i)
        {
            printf("%d %d\n",a1[i],b1[i]); 
        }
        return 0;
}
