#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct soldier
{
   int b,j;
   bool operator<(const soldier&a)const
   {
      return j>a.j; 
   }
}so[1010];
const int INF=0x3f3f3f3f;
int main()
{
   int n,t=0;
   while(~scanf("%d",&n)&&n)
   {
      for(int i=1;i<=n;++i)
          scanf("%d%d",&so[i].b,&so[i].j);
      sort(so+1,so+1+n);
      int dif=0,ans=0;
      for(int i=1;i<=n;++i)
      {
         int res;
         res=dif+so[i].b+so[i].j;
         dif+=so[i].b;
         ans=max(ans,res); 
      }
    printf("Case %d: %d\n",++t,ans);    
   } 
   return 0;
}
