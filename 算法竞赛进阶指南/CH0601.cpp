#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int a[maxn],b[maxn],c[maxn];
void merge(int l,int mid,int r,int a[])
{
   int i=l,j=mid+1,k=l;
   while(i<=mid&&j<=r)
   {
      if(a[i]<a[j])
         c[k++]=a[i++];
      else c[k++]=a[j++]; 
   } 
   while(i<=mid)
       c[k++]=a[i++];
   while(j<=r)
       c[k++]=a[j++];
}
ll solve(int l,int r,int m,int a[])
{
   ll cnt=0;
   while(l<=r&&m)cnt+=(ll)(a[r]-a[l])*(a[r]-a[l]),++l,--r,--m;
   return cnt; 
}
int main()
{
   int k,n,m;
   ll t;
   scanf("%d",&k);
   while(k--)
   {
      scanf("%d%d%lld",&n,&m,&t);
      for(int i=1;i<=n;++i)
          scanf("%d",&a[i]);
      b[1]=a[1];
      int p=1,l=1,r=1,ans=1;
      while(r<n)
      {
          int rr=r+p;if(rr>n)rr=n;
         for(int i=r+1;i<=rr;++i)
            b[i]=a[i];
         sort(b+1+r,b+rr+1);
         merge(l,r,rr,b);
         if(solve(l,rr,m,c)>t)p/=2;
         else
         {
            r=rr;p*=2;
            for(int i=l;i<=r;++i)b[i]=c[i]; 
         } 
         if(!p)l=r+1,p=1,++ans;
      }
      printf("%d\n",ans);
   }
   return 0;
}
