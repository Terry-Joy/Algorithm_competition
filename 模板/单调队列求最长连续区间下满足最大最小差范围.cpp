#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1e5+5;
int a[maxn],qmax[maxn],qmin[maxn],h1,t1,h2,t2,now,n,m,k,ans=0;
int main()
{
   while(~scanf("%d%d%d",&n,&m,&k))
   {
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      now=0;
      h1=h2=1;t1=t2=ans=0;
      for(int i=1;i<=n;++i)
      {
         while(h1<=t1&&a[i]>=a[qmax[t1]])t1--;
             qmax[++t1]=i;
         while(h2<=t2&&a[i]<=a[qmin[t2]])t2--;
             qmin[++t2]=i;
         while(h1<=t1&&h2<=t2&&a[qmax[h1]]-a[qmin[h2]]>k)//通过右移两个队列中的最小下标
            now=qmax[h1]<qmin[h2]?qmax[h1++]:qmin[h2++];
         if(h1<=t1&&h2<=t2&&a[qmax[h1]]-a[qmin[h2]]>=m)//<m不管怎样移动都无解
            ans=max(ans,i-now);        
      } 
      printf("%d\n",ans);
   } 
   return 0; 
}
