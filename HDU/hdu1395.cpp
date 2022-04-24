#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4;
bool v[maxn];
int phi[maxn],prime[maxn],cnt=0,e[maxn];
int mypow(int a,int b,int p)
{
   int ans=1;
   while(b)
   {
      if(b&1)ans=ans*a%p;
      a=a*a%p;
      b>>=1; 
   } 
   return ans;
}
void init()
{
    v[1]=v[0]=1;
    phi[1]=1;
    for(int i=2;i<=maxn-5;++i)
    {
       if(!v[i])phi[i]=i-1,prime[++cnt]=i;
       for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j)
       {
          v[prime[j]*i]=1;
          if(i%prime[j]==0)
          {
             phi[prime[j]*i]=phi[i]*prime[j];
             break; 
          } 
          else phi[prime[j]*i]=phi[prime[j]]*phi[i];
       } 
    }
}
int main()
{
    init();
    int n;
    while(~scanf("%d",&n))
    {
       if(n%2==0||n==1)
          printf("2^? mod %d = 1\n",n);
       else 
       { 
          int id=0; 
          for(int i=1;;++i)
             if(e[i])
                e[i]=0;
             else break; 
          int tmp=phi[n];
          for(int i=1;i*i<=tmp;++i)
          {
             if(tmp%i==0){ 
                e[++id]=i;
                if(tmp/i!=i)
                    e[++id]=tmp/i;
             } 
          } 
          sort(e+1,e+1+id);
          for(int i=1;i<=id;++i)
             if(mypow(2,e[i],n)==1)
             { 
                printf("2^%d mod %d = 1\n",e[i],n);
                break;
             }
       } 
    }
    return 0;
}
