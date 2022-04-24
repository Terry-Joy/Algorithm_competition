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
const int maxn=1e5+10;
int a[maxn];

int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      bool flag=1;
      for(int i=1;i<n;++i)
      {
         if(a[i]+1==a[i+1]||a[i]>a[i+1])continue;
         else
         {
            flag=0;
            break; 
         } 
      } 
      if(!flag)
          puts("No");
      else 
          puts("Yes");
   }
   return 0; 
}
