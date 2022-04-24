#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   int cnt=0;
   for(int i=1;i<=n;++i)scanf("%d",&a[i]);
   int ans=0;
   for(int i=1;i<=30;++i)//枚举最大值
   {
       cnt=0;
       for(int j=1;j<=n;++j)
       {
          if(a[j]>i)//区间断开
             cnt=0;
          else
          {
             cnt+=a[j];
             if(cnt<0)      //区间断开
                cnt=0;
             else
                ans=max(ans,cnt-i);//不存在的最大值一定不会更新答案
          } 
       } 
   }
   printf("%d\n",ans);
   return 0; 
}
