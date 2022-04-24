#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
char s[710];
const ll mod=1e9+7;
ll dp[710][710][3][3];
stack<int>st;
int mp[750];
void dfs(int i,int j)//dfs(i,j)表示解决了ij内计数问题
{
   if(i+1==j)
   { 
      for(int k=1;k<=2;++k)
         dp[i][j][0][k]=dp[i][j][k][0]=1;
      return;
   }
   if(mp[i]==j)
   {
      dfs(i+1,j-1);//相等就直接递归 
      for(int l=0;l<3;++l) 
          for(int r=0;r<3;++r)
          {
             if(l!=1)
                dp[i][j][1][0]=(dp[i][j][1][0]+dp[i+1][j-1][l][r])%mod;
             if(r!=1)
                dp[i][j][0][1]=(dp[i][j][0][1]+dp[i+1][j-1][l][r])%mod; 
             if(l!=2)
                dp[i][j][2][0]=(dp[i][j][2][0]+dp[i+1][j-1][l][r])%mod;
             if(r!=2)
                dp[i][j][0][2]=(dp[i][j][0][2]+dp[i+1][j-1][l][r])%mod;
          }
   }
   else
   { 
      int m=mp[i];
      dfs(i,m);             //不相等就分开两边递归求
      dfs(m+1,j);
      for(int l=0;l<3;++l)
          for(int r=0;r<3;++r)
              for(int a=0;a<3;++a)
                  for(int b=0;b<3;++b)
                  {
                     if(a==b&&a!=0)continue;
                     dp[i][j][l][r]=(dp[i][j][l][r]+dp[i][m][l][a]*dp[m+1][j][b][r]); 
                     dp[i][j][l][r]%=mod;
                  }
   }
}
int main()
{
   scanf("%s",s+1);
   int k=strlen(s+1);
   for(int i=1;i<=k;++i)
   {
      if(s[i]=='(')
        st.push(i);
      else
      {
         mp[st.top()]=i;
         mp[i]=mp[st.top()];  
         st.pop();
      }
   }
   dfs(1,k);
   ll ans=0;
   for(int l=0;l<3;++l)
       for(int r=0;r<3;++r)
           ans=(ans+dp[1][k][l][r])%mod;
   printf("%lld\n",ans);
   return 0; 
}
