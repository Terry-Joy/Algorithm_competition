#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
ll fac[100];
ll mul(ll a,ll b,ll p)
{
   if(p<=1000000000)return a*b%p;
   else if(p<=1000000000000ll)return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p; 
}
ll mypow(ll a,ll b,ll p)
{
   ll ans=1;
   while(b){ 
       if(b&1)ans=mul(ans,a,p);
       a=mul(a,a,p);
       b>>=1;
   } 
   return ans;
}
ll divide(ll x)
{
   ll ans=x;
   for(int i=2;i*i<=x;++i)
   {
      if(x%i==0){ 
         ans=ans/i*(i-1);
         while(x%i==0)x/=i;
      } 
   } 
   if(x>1)ans=ans/x*(x-1);
   return ans;
}
int main()
{
   ll l;
   int f=0;
   while(~scanf("%lld",&l)&&l)
   { 
       ll t=9*l/gcd(8,l);
       ll sum=divide(t);
       int cnt=0;
       for(ll i=1;i*i<=sum;++i)
       {
           if(sum%i==0)
           {
              fac[++cnt]=i;
              if(i!=sum/i)fac[++cnt]=sum/i; 
           } 
       } 
       sort(fac+1,fac+1+cnt);
       bool flag=0;
       for(int i=1;i<=cnt;++i)
           if(mypow(10,fac[i],t)==1)
           {
              printf("Case %d: %lld\n",++f,fac[i]);
              flag=1;
              break; 
           }
           if(!flag)
           printf("Case %d: 0\n",++f);
   } 
   return 0; 
}
