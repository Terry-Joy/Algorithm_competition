#include<iostream>
#include<cstdio>
using namespace std;
int n,m,fa[200005],val[200005],cur;
void init()
{
   for(int i=0;i<=n;++i)
   {
      fa[i]=i;val[i]=0; 
   } 
    cur=0;
}
int find(int x)
{
    if(x!=fa[x])
    {
       int t=fa[x];
       fa[x]=find(fa[x]);
       val[x]+=val[t]; 
    }
    return fa[x];
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
       init(); 
       for(int i=0;i<m;++i)
       {
          int a,b,c;
          scanf("%d%d%d",&a,&b,&c);
           a-=1;
           int fx=find(a);
           int fy=find(b);
           if(fx!=fy)
           {
              fa[fy]=fx;

              val[fy]=c+val[a]-val[b]; 
           }
           else{
                if(val[b]-val[a]!=c)
                    cur++;
           }
       }
       printf("%d\n",cur);
    }
    return 0;
}
