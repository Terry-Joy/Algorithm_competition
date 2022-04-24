#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=110;
double w[N][N],la[N],lb[N],x1[N],x2[N],y1[N],y2[N];//左右顶标
bool va[N],vb[N];
int match[N];
int n;
double delta,upd[N];
bool dfs(int x)
{
   va[x]=1;
   for(int y=1;y<=n;++y)
   {
      if(!vb[y])
      {
         if(la[x]+lb[y]-w[x][y]<=1e-9)
         {
            vb[y]=1;
            if(!match[y]||dfs(match[y]))
            {
               match[y]=x;
               return true; 
            } 
         } 
      } 
      else upd[y]=min(upd[y],la[x]+lb[y]-w[x][y]);
   }
  return false; 
}

void KM()
{
   for(int i=1;i<=n;++i)
   { 
      la[i]=-(1<<30);
      lb[i]=0;
      for(int j=1;j<=n;++j)
          la[i]=max(la[i],w[i][j]);
      for(int i=1;i<=n;++i)
      {
         while(true)
         {
            memset(va,0,sizeof(va));
            memset(vb,0,sizeof(vb));
            for(int j=1;j<=n;++j)upd[j]=1e10;
            if(dfs(i))break;
            for(int j=1;j<=n;++j)
               if(!vb[j])delta=min(delta,upd[j]);
            for(int j=1;j<=n;++j)   //修改顶标
            {
               if(va[j])la[j]-=delta;
               if(vb[j])lb[j]+=delta; 
            } 
         } 
      }
   }
}
int main()
{
   scanf("%d",&n);
   int i,j;
   for(i=1;i<=n;++i)
      scanf("%d%d",&x1[i],&y1[i]);
   for(j=1;j<=n;++j)
      scanf("%d",&x2[j],&y2[j]); 
   for(i=1;i<=n;++i)
       for(j=1;j<=n;++j)
           w[i][j]=-1*sqrt(1.0*(x1[i]-x2[j])*(x1[i]-x2[j])+1.0*(y1[i]-y2[j])*(y1[i]-y2[j]));
   KM();
   for(i=1;i<=n;++i)
       printf("%d\n",match[i]);
   return 0;
}
