#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{ 
   int t,n,m,x;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d%d",&x,&n,&m);
      if(x<=m*10){ puts("YES");continue;}
      while(n>0)
      {
         if(x/2+10<x)
         {
            x=x/2+10;
            n--; 
         } 
         else break;
      }
      if(x<=m*10)
          puts("YES");
      else puts("NO");
   } 
   return 0;
}
