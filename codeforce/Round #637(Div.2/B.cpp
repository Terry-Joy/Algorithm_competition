#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int a[maxn],sum[maxn],n,k;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&n,&k);
      for(int i=1;i<=n;++i)
      {    
          scanf("%d",&a[i]);
          sum[i]=0;
      }
      for(int i=2;i<=n-1;++i)
      {
         if(a[i]>a[i-1]&&a[i]>a[i+1])sum[i]++;
         sum[i]+=sum[i-1];
      } 
      int i,l=1;
      int ans=-1;
      for(i=1;i<=n-k+1;++i)
      { 
            if(ans<sum[i+k-2]-sum[i])
             {
                ans=sum[i+k-2]-sum[i];
                l=i; 
            }
      }
      printf("%d %d\n",ans+1,l);
   }
   return 0; 
}
