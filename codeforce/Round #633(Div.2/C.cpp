#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int a[100010],lg[40];
int main()
{
   lg[1]=1;
   for(int i=2;i<=33;++i)
       lg[i]=(lg[i-1]<<1);
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       for(int i=1;i<=n;++i)
          scanf("%d",&a[i]); 
       int mx=a[1],de=0;
       for(int i=2;i<=n;++i)
       {
          mx=max(mx,a[i]);
          if(a[i]<mx)de=max(de,mx-a[i]); 
       }
       int t=0;
       while(de>0)
       {
          t++;
          de-=lg[t]; 
       }
       printf("%d\n",t);
   }
   return 0; 
}
