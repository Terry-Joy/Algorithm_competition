#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[105][105];
char s[105];
int check(int i,int j)
{
   if((s[i]=='('&&s[j]==')')||(s[i]=='[')&&s[j]==']')
      return 2;
   return 0; 
}
int main()
{
    while(~scanf("%s",s+1)&&s[1]!='e')
    {
        int sum=strlen(s+1);
        for(int i=1;i<=sum;++i)
           for(int j=i;j<=sum;++j)
              dp[i][j]=0;
        for(int len=2;len<=sum;++len)
        {
           for(int i=1;i+len-1<=sum;++i)
            {
               int j=i+len-1;
                   dp[i][j]=max(dp[i][j],dp[i+1][j-1]+check(i,j));//自己单独扩增成功 
               for(int k=i;k<=j-1;++k)
                   dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);                   //自己单独扩增失败+两个合并的情况  
            }
        } 
        printf("%d\n",dp[1][sum]);
    }
    return 0;
}
