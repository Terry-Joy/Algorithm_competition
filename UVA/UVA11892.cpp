#include<iostream>
#include<cstdio>

using namespace std;
typedef long long ll;
int p[1600],c[1600];
int main()
{
   int n;
   while(~scanf("%d",&n)&&n)
   {
       int f=n;
       int cnt=0;
       for(int i=2;i*i<=n;++i)
       {
          if(n%i==0){ 
             p[++cnt]=i;c[cnt]=0;
             while(n%i==0)
                n/=i,c[cnt]++;
          } 
       } 
       if(n>1)p[++cnt]=n,c[cnt]=1;
       ll ans=1;
       for(int i=1;i<=cnt;++i)
           ans*=(2*c[i]+1);//乘法原理
       printf("%d %lld\n",f,ans/2+1);
   } 
   return 0; 
}
