#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dp[110][110];
char s1[110],s2[110];
int ans[110];
int main()
{
   while(~scanf("%s %s",s1+1,s2+1)) 
   {
      int len1=strlen(s2+1);
      for(int j=1;j<=len1;++j)  //先刷空串变成B
      { 
         for(int i=j;i>=1;--i)
         {  
             dp[i][j]=dp[i+1][j]+1; //无优化刷
             for(int k=i+1;k<=j;++k)
                 if(s2[i]==s2[k])
                     dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
         }
      }
      //通过新字符串和dp数组更新答案
      for(int i=1;i<=len1;++i)
          ans[i]=dp[1][i];
      for(int i=1;i<=len1;++i)
      {
         if(s1[i]==s2[i])           //第i个相等可以不刷
            ans[i]=ans[i-1];
         else
             for(int j=1;j<=i-1;++j)        //分割区间枚举最优解
                ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
      }
     printf("%d\n",ans[len1]);
   }
   return 0; 
}
