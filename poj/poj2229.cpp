#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll dp[maxn];
int a[20],mod=1e9;
int main()
{
   int n;
   scanf("%d",&n);
   int k=log(n)/log(2);
   a[1]=1;
   for(int i=2;i<=k+1;++i)
       a[i]=(a[i-1]<<1);
   dp[0]=1;
   for(int i=1;i<=k+1;++i)
      for(int j=a[i];j<=n;++j)
      {
          dp[j]+=dp[j-a[i]];
          if(dp[j]>mod)dp[j]%=mod;
      }
   printf("%lld",dp[n]);
   return 0; 
}
