#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
   int t,a,b;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&a,&b);
      if(b%a!=0)
         puts("-1");
      else
         {
            printf("%d %d\n",a,b); 
         }
   }
   return 0;
}
