#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=5e5+5;
const int INF=0x7FFFFFFF;
int ans1[maxn],ans2[maxn],a[maxn],q[maxn],t;
int main()
{
   int k,n,f=0;
   scanf("%d",&k);
   while(k--)
   {
      t=0; 
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
          scanf("%d",&a[i]);
      for(int i=1;i<=n;++i)
      {
         ans1[i]=0;
         while(t>0&&a[i]>a[q[t]])ans1[i]=q[t--];
         q[++t]=i;
      }
      t=0;
      for(int i=n;i;--i)
      {
         ans2[i]=0;
         while(t>0&&a[i]>a[q[t]])ans2[i]=q[t--];
         q[++t]=i;
      }
      printf("Case %d:\n",++f);
      for(int i=1;i<=n;++i)
          printf("%d %d\n",ans1[i],ans2[i]);
   }
   return 0; 
}
