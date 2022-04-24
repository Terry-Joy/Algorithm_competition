#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int u[maxn],v[maxn],in[maxn],w[maxn];
int main()
{
   int n;

   scanf("%d",&n);
   for(int i=1;i<n;++i)
   {
        scanf("%d%d",&u[i],&v[i]);
        in[u[i]]++,in[v[i]]++;
        w[i]=-1;
   }
   int m=0;
   for(int i=1;i<n;++i)
   {
      if(in[i]>=3)
      {
         for(int j=1;j<n;++j)
         {
            if(u[j]==i||v[j]==i)
            {
               w[j]=m++;
               if(m==3)break; 
            }
         } 

           break; 
      } 
   }
   for(int i=1;i<n;++i)
       if(w[i]==-1)w[i]=m++;
   for(int j=1;j<n;++j)
       printf("%d\n",w[j]);
   return 0; 
}
