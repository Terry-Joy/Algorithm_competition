#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=600;
int n,s,p,fa[N];
double x[N],y[N],edge2[N];
struct Node
{
   int x,y;
   double ed;
   bool operator<(const Node&a)const{
   		return ed<a.ed;
   } 
}edge[N*N];
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k=0;
        scanf("%d%d",&n,&s);
        for(int i=1;i<=s;++i)
            fa[i]=i;
        for(int i=1;i<=s;++i)
            scanf("%lf%lf",&x[i],&y[i]);
        for(int i=1;i<=s;++i)
            for(int j=i+1;j<=s;++j)
            { 
                edge[++k].ed=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                edge[k].x=i;
                edge[k].y=j;
            }
        sort(edge+1,edge+k+1);
        int j=0;
        for(int i=1;i<=k;++i)
        {   
            int fx=find(edge[i].x);
            int fy=find(edge[i].y);
            if(fx==fy)continue;
            else
            {
               fa[fy]=fx;
               edge2[++j]=edge[i].ed;
            }
        }
        printf("%.2lf\n",edge2[j-(n-1)]);
    }
    return 0;
}
