#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e6+10;
ll A[maxn],C[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
       ll ave=0;
       for(int i=1;i<=n;++i)
       {    
           scanf("%lld",&A[i]);
           ave+=A[i];
       } 
      ll M=ave/n;
      C[1]=0;
      for(int i=2;i<=n;++i)
          C[i]=C[i-1]+A[i-1]-M;
      sort(C+1,C+1+n);
      ll x1=C[(n+1)/2];
      ll ans=0;
      for(int i=1;i<=n;++i)
           ans+=abs(x1-C[i]);
      printf("%lld\n",ans); 
    }
    return 0;
}
