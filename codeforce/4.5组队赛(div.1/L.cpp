#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
char s[65];
int v[65];
ll mypow(ll a,ll b)
{
   ll ans=1;
   while(b)
   {
      if(b&1)
         ans=ans*a;
         a=a*a;
         b>>=1;
   } 
   return ans;
}
int main()
{
    ll a;
    int de=0;
    ll sum=0;
    memset(v,0,sizeof(v));
    scanf("%lld",&a);
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;++i)
    {
       if(s[i]=='1')
       {
            v[i]=1;
            sum+=mypow(2,len-i-1);
       } 
    }
    int f=len;
    while(sum>a)
    {
        int k=1;
        while(k<len)
        {
            if(v[k]==1)
            {
               v[k]=2;
               break; 
            }
            k++;
        }
        sum=0;
        f--;
        if(k!=len)
        {
           int now=0;
           for(int i=len-1;i>=0;--i)
           {
              if(v[i]==1)
              {
                 sum+=mypow(2,now);
                 now++; 
              } 
              else if(v[i]==0)
                  now++;
           } 
        }
        else 
            sum+=mypow(2,f-1);
            de++;
    }
    printf("%d\n",de);
    return 0;
}
