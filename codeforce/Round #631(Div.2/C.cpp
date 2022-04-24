#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
using namespace std;
ll sum[100100],a[100100];
int n,m;
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;++i)
   {    
       scanf("%lld",&a[i]);
       if(i+a[i]-1>n)
       {
          cout<<-1;
          return 0; 
       }
   }
   for(int i=m;i>=1;--i)
     sum[i]=sum[i+1]+a[i];
   if(sum[1]<n)
   { 
        cout<<-1;return 0;
   }
   for(ll i=1;i<=m;++i)
      a[i]=max(i,n-sum[i]+1);
   for(int i=1;i<=m;++i)
     cout<<a[i]<<" ";  
   return 0; 
}
