#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main()
{
   int t,n,s;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&n,&s);
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      int h=1,t=1,sum=0,ans=n+1;
      for(int i=1;i<=n;++i)
      {
         sum+=a[i];
         t=i;
         while(sum>=s)
         {
            ans=min(ans,t-h+1);
            sum-=a[h++]; 
         } 
      } 
      if(ans>n)puts("0");
      else printf("%d\n",ans);
   } 
   return 0; 
}
