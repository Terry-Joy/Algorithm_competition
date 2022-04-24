#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n,x,m;
      scanf("%d%d%d",&n,&x,&m);
      int a,b,ans=0,j=m+1,l=n+1,r=-1;
      for(int i=1;i<=m;++i)
      {
          scanf("%d%d",&a,&b);
          if(a<=x&&b>=x)
          { 
             l=a,r=b;
             j=i;
             break;   
          }       
      }
      if(j==m+1)
      {
         puts("1");
         continue; 
      }
      for(int i=j+1;i<=m;++i)
      {
         scanf("%d%d",&a,&b);
         if(b<l||a>r)continue;
         l=min(l,a);
         r=max(r,b); 
      }
      printf("%d\n",r-l+1);
   } 
   return 0; 
}
