#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=5e3+5;
int l[maxn],r[maxn],a[maxn],sum[maxn];
int main()
{
   int n,q;
   scanf("%d%d",&n,&q);
   for(int i=1;i<=q;++i)
   {
      scanf("%d%d",&l[i],&r[i]);
      for(int j=l[i];j<=r[i];++j)
      sum[j]++; 
   }
   int ans=0;
   for(int i=1;i<=q;++i)
   {
      int num=0;
      for(int j=l[i];j<=r[i];j++)
         sum[j]--;
      for(int j=1;j<=n;++j)
      {
         if(sum[j]==1)a[j]=a[j-1]+1;
         else a[j]=a[j-1];
         if(sum[j])num++; 
      } 
      for(int j=i+1;j<=q;++j)
          ans=max(ans,num-(a[r[j]]-a[l[j]-1]));
      for(int j=l[i];j<=r[i];j++)
          sum[j]++;
   }
    printf("%d\n",ans);
   return 0; 
}
