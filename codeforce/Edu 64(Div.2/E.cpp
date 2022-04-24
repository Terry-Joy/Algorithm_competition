#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int a[maxn],pos[maxn],l[maxn],r[maxn],s[maxn];
ll ans;
int main()
{
   int n;
   scanf("%d",&n);
   int top=0;
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]),pos[a[i]]=i;
   for(int i=1;i<=n;++i)        //单调栈求a[i]在哪个区间最大或最小
   {
      while(top&&a[s[top]]<a[i])top--;
      l[i]=s[top]+1;s[++top]=i; 
   }
   top=0,s[top]=n+1;
   for(int i=n;i>=1;--i)//反过来扫一次
   {
      while(top&&a[s[top]]<a[i])top--;
      r[i]=s[top]-1,s[++top]=i; 
   }
   for(int i=1;i<=n;++i)
   {
      if(i-l[i]<r[i]-i)             //启发式
      {
         for(int j=l[i];j<i;++j)
            if(pos[a[i]-a[j]]>i&&pos[a[i]-a[j]]<=r[i])ans++; 
      } 
      else for(int j=i+1;j<=r[i];j++)
        if(pos[a[i]-a[j]]>=l[i]&&pos[a[i]-a[j]]<i)ans++;
      
   }
   printf("%lld",ans);
   return 0; 
}
