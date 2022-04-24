#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+5;
const int maxm=1e7+5;
const int top=670000;
int n,a,b1[maxn],b2[maxn],v[maxm],prime[top],cnt=0,INF=1e7; 

void init()
{
	cnt=0;
    for(int i=2;i<=n;++i)
    {
       if(!v[i])v[i]=i,prime[++cnt]=i;
       for(int j=1;j<=cnt;++j)
       {
          if(prime[j]>v[i]||prime[j]>n/i)break;
          v[i*prime[j]]=prime[j]; 
       } 
    } 
}
int main()
{
   scanf("%d",&n);
   init();
   for(int i=1;i<=n;++i)
       b1[i]=b2[i]=-1;
   for(int i=1;i<=n;++i)
   {
       scanf("%d",&a);
       int p=v[a];
       while(a%p==0)
       {
          a/=p; 
       }
       if(a!=1)
           b1[i]=p,b2[i]=a;
   } 
   for(int i=1;i<=n;++i)
       printf("%d ",b1[i]);
   puts("");
   for(int i=1;i<=n;++i)
       printf("%d ",b2[i]);
   return 0; 
}
