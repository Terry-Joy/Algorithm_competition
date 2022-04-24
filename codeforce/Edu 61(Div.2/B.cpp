#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
int a[300005],sum[300005];
int main()
{
   int n;
   scanf("%d",&n);
   ll ans=0;
   for(int i=1;i<=n;++i)
   {  
       scanf("%d",&a[i]);
       ans+=a[i];
   }
   sort(a+1,a+1+n);
   int k;
   scanf("%d",&k);
   for(int i=1;i<=k;++i)
   {
      int b;
      scanf("%d",&b);
      printf("%lld\n",ans-a[n-b+1]); 
   }
   return 0; 
}
