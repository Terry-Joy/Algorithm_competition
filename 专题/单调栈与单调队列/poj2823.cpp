#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=1e6+5;
int a[maxn],qmax[maxn],qmin[maxn],h1,t1,h2,t2,ans1[maxn],ans2[maxn];
int main()
{
   int n,k,cnt1=0,cnt2=0;
   scanf("%d%d",&n,&k);
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]);
   for(int i=1;i<=n;++i)
   {
       while(h1<=t1&&a[i]<=a[qmin[t1]])t1--;
           qmin[++t1]=i;
       while(h2<=t2&&a[i]>=a[qmax[t2]])t2--;
           qmax[++t2]=i;
       while(h1<=t1&&i-qmin[h1]+1>k)h1++;
       while(h2<=t2&&i-qmax[h2]+1>k)h2++; 
       if(i>=k)
          ans1[++cnt1]=a[qmin[h1]],ans2[++cnt2]=a[qmax[h2]]; 
   } 
   for(int i=1;i<=cnt1;++i)
       printf("%d ",ans1[i]);
   puts("");
   for(int i=1;i<=cnt2;++i)
       printf("%d ",ans2[i]);
   return 0; 
}
