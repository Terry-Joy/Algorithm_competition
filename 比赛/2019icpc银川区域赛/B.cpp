#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[1005][1005];
int r[1005],c[1005];
const int INF=0x3f3f3f3f;
int main()
{
   int n;
   scanf("%d",&n);
   int q,w;
   for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
      { 
         scanf("%d",&a[i][j]);
         if(a[i][j]==-1)a[i][j]=INF,q=i,w=j;
      }
   int mx;
   for(int i=1;i<=n;++i)
   {
       mx=INF;
       for(int j=1;j<=n;++j)
       {
          if(a[i][j]<mx&&a[i][j]!=-1) 
                mx=a[i][j];
       } 
       r[i]=mx;
   }
   for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
          a[i][j]-=r[i];

   for(int i=1;i<=n;++i)
   {
      mx=INF; 
      for(int j=1;j<=n;++j)
      {
          if(a[j][i]<mx&&a[j][i]!=-1) 
              mx=a[j][i];
      } 
      c[i]=mx;
   }
   printf("%d",r[q]+c[w]);
   return 0; 
}
