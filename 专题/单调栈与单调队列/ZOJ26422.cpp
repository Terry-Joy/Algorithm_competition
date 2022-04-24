#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int st[maxn],a[maxn],t,L[maxn];
ll w[maxn];
int main()
{
   int n;
   while(~scanf("%d",&n))
   {
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      t=a[n+1]=0;
      ll ans=0;
      int l=1,r=1;
      for(int i=1;i<=n+1;++i)
      {
         if(a[i]>st[t])st[++t]=a[i],w[t]=a[i],L[t]=i;
         else
         {
            ll wd=0;
            while(a[i]<st[t])//更新的时候顺便记录往左的最长宽度
            {
                wd+=w[t];
                if(1ll*wd*st[t]>ans)
                { 
                    ans=1ll*wd*st[t];
                    r=i-1;
                    l=L[t];//w[]和L[]都是累积的
                }
                t--;
            } 
            st[++t]=a[i];w[t]=wd+a[i];
         }   
      } 
      printf("%lld\n",ans);
      printf("%d %d\n",l,r);
   } 
   return 0; 
}
