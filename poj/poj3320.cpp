#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
const int INF=0x3f3f3f3f;
int a[maxn],has[maxn],hap[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]),has[i]=a[i];
   sort(has+1,has+1+n);                   //排序去重离散化
   int m=unique(has+1,has+1+n)-(has+1);
   for(int i=1;i<=n;++i)
       a[i]=lower_bound(has+1,has+1+n,a[i])-has;
   int cnt=0,ans=INF,r=1,l=1;
   for(int i=1;i<=n;++i)
   {
      if(++hap[a[i]]==1)cnt++;
      r=i;
      while(cnt>=m)
      {
          ans=min(ans,r-l+1);
          if(--hap[a[l++]]==0)cnt--;    
      } 
   } 
   printf("%d\n",ans);
   return 0; 
}
