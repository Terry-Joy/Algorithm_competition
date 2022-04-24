#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],b[maxn],pos[maxn],cnt[maxn];
const int INF=0x3f3f3f3f;
int main()
{
   int n,x;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   {
       scanf("%d",&a[i]);
       pos[a[i]]=i;
   }
   for(int i=1;i<=n;++i)
   { 
       scanf("%d",&b[i]);
       ++cnt[(i-pos[b[i]]+n)%n];           //统计的是对应移位的个数     
   }
   int ans=1;
   for(int i=1;i<=n;++i)
       ans=max(ans,cnt[i]);
   printf("%d\n",ans);
   return 0; 
}
