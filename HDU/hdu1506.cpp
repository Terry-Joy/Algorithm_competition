//单调栈求平面上最大矩形并面积
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],w[maxn],st[maxn];
int main()
{
   int n; 
   while(~scanf("%d",&n)&&n)
   {
      for(int i=1;i<=n;++i)
         scanf("%d",&a[i]);
      ll ans=0;
      int top;
      a[n+1]=top=0;//最后弹出用
      for(int i=1;i<=n+1;++i)
      {
         if(a[i]>st[top])
            st[++top]=a[i],w[top]=1;
         else
         { 
            int wd=0;
            while(st[top]>a[i])
            {
               wd+=w[top];
               ans=max(ans,1ll*wd*st[top--]);
            }
            st[++top]=a[i],w[top]=wd+1;//相同的时候也算进去了
         } 
      } 
      printf("%lld\n",ans);
   }
   return 0; 
}
