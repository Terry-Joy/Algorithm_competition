#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
   return b?gcd(b,a%b):a; 
}
int main()
{
   int t,a,c;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d",&a,&c);
      if(c%a)puts("NO SOLUTION\n"); 
      else
      {
         int b=c/a,t=1,g;
         while((g=gcd(a,b))!=1)
         {
            t*=g;
            a/=g; 
         } 
         printf("%d\n",b*t);
      }
   } 
   return 0;
}
