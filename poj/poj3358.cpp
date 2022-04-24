#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
ll gcd(int a,int b){ return b?gcd(b,a%b):a;}
ll mypow(ll a,ll b,ll p)
{
   ll ans=1;
   while(b){ 
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
   } 
   return ans;
}
ll eulter(ll x)
{
   ll ans=x; 
   for(int i=2;i*i<=x;++i)
   {
      if(x%i==0)
      {
         ans=ans/i*(i-1);
         while(x%i==0)x/=i; 
      } 
   } 
   if(x>1)ans=ans/x*(x-1);
   return ans;
}
int main()
{
   ll p,q;
   int f=0;
   while(~scanf("%lld/%lld",&p,&q))
   { 
        ll x=1;
        printf("Case #%d: ",++f);
        if(!p)
        { 
            printf("%d,%d\n",1,1);
            continue;
        }
        ll G=gcd(p,q);
        p/=G;//不能改变后接着gcd
        q/=G;
        while(q%2==0)
        {
           x++;
           q/=2; 
        }
        ll fai=eulter(q);
        ll y;
        for(int i=1;i*i<=fai;++i)
        {   
            if(fai%i==0&&mypow(2,i,q)==1){ y=i;break;}
            if(fai%i==0&&mypow(2,fai/i,q)==1){ y=fai/i;}
        }
       printf("%lld,%lld\n",x,y); 
   }
   return 0; 
}
