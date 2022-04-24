#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int prime[15];
int main()
{
   int ans=0,n;
   while(~scanf("%d",&n)&&n){ 
       int cnt=0;
       ans=n;
      for(int i=2;i*i<=n;++i)
      {
         if(n%i==0) 
         {
            prime[++cnt]=i;
            ans=ans/i*(i-1);   
            while(n%i==0)
                n/=i;
         }
      }
      if(n>1)
          ans=ans/n*(n-1);
      printf("%d\n",ans);
   } 
   return 0; 
}
