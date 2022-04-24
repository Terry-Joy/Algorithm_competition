#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll ten[65];
int ans[65];
int main()
{
   ten[1]=ten[2]=9;
   for(int i=3;i<=64;++i)
      ten[i]=9*pow(10,(i-1)/2);
   int n;
   while(~scanf("%d",&n)&&n)
   {
       int i=1;
       while(n-ten[i]>0)
       {
          n-=ten[i];
          i++;
       }
       for(int j=1;j<=i;++j)
           ans[j]=0;
       int len=(i+1)/2;
       int len2=len;
       ans[1]=1;
       n-=1;
       while(n)
       {
          ans[len]+=n%10;
          n/=10;
          len--; 
       } 
       for(int j=i;j>=len2;--j)
          ans[j]=ans[i+1-j];
       for(int j=1;j<=i;++j)
          printf("%d",ans[j]);
       putchar('\n'); 
   } 
   return 0; 
}
