#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[510][510];
const int INF=0x3f3f3f3f;
int main()
{
   int n;
   scanf("%d",&n);
   for(int len=3;len<=n;++len)
   {
      for(int i=1;i+len-1<=n;++i)
      {
         int j=i+len-1;
         dp[i][j]=INF;
         for(int k=i+1;k<=i-1;++k)
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+i*j*k); 
      } 
   }
   cout<<dp[1][n];
   return 0; 
}
