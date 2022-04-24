#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int main()
{
   int n,z;
   scanf("%d%d",&n,&z);
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]);
   sort(a+1,a+1+n);
   ll idx=(n+1)/2;
   int ans=0;
   for(int i=1;i<=n/2;++i,idx++)
   {
      while(idx<=n&&a[idx]-a[i]<z)
         idx++;
      if(idx<=n)
         ans++;
      else break; 
   }
   cout<<ans;
   return 0; 
}
