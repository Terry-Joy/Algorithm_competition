#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=4e4+100,M=4e4+100;
int n,m,dx[N],dy[M],k,ans[N],fa[N];
struct edge
{ 
    int a,b,l;
    char D[3];
}ed[N];
struct query
{
   int a,b,t,id;
   bool operator<(const query&a)const
   {
       return t<a.t;
   } 
}que[M];
int find(int x)
{
    if(x==fa[x])return x;
    else
    { 
        int t=fa[x];
        fa[x]=find(fa[x]);
        dx[x]+=dx[t];
        dy[x]+=dy[t];
        return fa[x];
    }
}
void init(int n)
{
   for(int i=1;i<=n;++i)
    { 
        fa[i]=i;
        dx[i]=0;
        dy[i]=0;
    }
}
int main()
{
     scanf("%d%d",&n,&m);
     char s[10];
     init(n);
     for(int i=1;i<=m;++i)
     {
        scanf("%d%d%d%s",&ed[i].a,&ed[i].b,&ed[i].l,ed[i].D);
     }
     scanf("%d",&k);
     for(int i=1;i<=k;++i)
     { 
         scanf("%d%d%d",&que[i].a,&que[i].b,&que[i].t);
         que[i].id=i;
    }
     sort(que+1,que+1+k);
     int j=1;
     for(int i=1;i<=m;++i)
     {
         int fx=find(ed[i].a),fy=find(ed[i].b);
         if(fx!=fy)
         {
            fa[fy]=fx;
            if(ed[i].D[0]=='E')                             //规定正东和正北为正方向
            {
               dx[fy]=dx[ed[i].a]+ed[i].l-dx[ed[i].b];
               dy[fy]=dy[ed[i].a]-dy[ed[i].b]; 
            }
            else if(ed[i].D[0]=='W')                        //北到南的点为正数，南到北为负数
            {
               dx[fy]=dx[ed[i].a]-dx[ed[i].b]-ed[i].l;
               dy[fy]=dy[ed[i].a]-dy[ed[i].b]; 
            }
            else if(ed[i].D[0]=='N')
            {
               dx[fy]=dx[ed[i].a]-dx[ed[i].b];
               dy[fy]=dy[ed[i].a]+ed[i].l-dy[ed[i].b]; 
            }
            else if(ed[i].D[0]=='S')
            {
               dx[fy]=dx[ed[i].a]-dx[ed[i].b];
               dy[fy]=dy[ed[i].a]-ed[i].l-dy[ed[i].b]; 
            }
         }
         while(i==que[j].t)
         {
            int f1=find(que[j].a),f2=find(que[j].b);
            if(f1!=f2)
               ans[que[j].id]=-1;
            else
            {
                ans[que[j].id]=abs(dx[que[j].a]-dx[que[j].b])+abs(dy[que[j].a]-dy[que[j].b]);
            }
            ++j;
         }
     }
     for(int i=1;i<=k;++i)
         printf("%d\n",ans[i]);
}
