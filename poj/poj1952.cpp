#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=5010;
int n,dp[maxn],a[maxn],sum[maxn];//表示以a[i]结尾的个数
bool v[maxn];//表示a[i]这个数是否有用
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]),v[i]=1;
   int ans=0;
   for(int i=1;i<=n;++i)
   { 
      dp[i]=1;  
      sum[i]=1;
      for(int j=i-1;j>=1;--j)
      { 
         if(a[j]>a[i]&&v[j])//只有非废数才能转移到后面
         { 
            if(dp[j]+1>dp[i])
            {
               dp[i]=dp[j]+1;
               sum[i]=sum[j];
            }
            else if(dp[j]+1==dp[i])
                sum[i]+=sum[j];
         }
         else if(a[i]==a[j])
         {
             if(dp[i]==1)//i、j之间没有能用的数 i变成废数 选择前面的
                 v[i]=0;
             break;      //a[i]==a[j]的时候，[j+1,i)转移到i已经计算过,[1,j-1]到i和j其实是一样的，不重复计数
         }
      }
      ans=max(dp[i],ans);
   }
   int num=0;
   for(int i=1;i<=n;++i)
       if(ans==dp[i])num+=sum[i];
   printf("%d %d\n",ans,num);
   return 0; 
}
