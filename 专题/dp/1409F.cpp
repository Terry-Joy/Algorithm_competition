#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,k;
char s1[205],s2[2];
int INF=0x3f3f3f3f,dp[205][205][205];
int main()
{ 
   cin>>n>>k;
   cin>>s1;
   cin>>s2;
   memset(dp,-0x3f,sizeof(dp));
   dp[0][0][0]=0;
   for(int i=0;i<=n-1;++i){ 
       for(int j=0;j<=min(k,i);++j)
          for(int f=0;f<=i;++f){ 
                if(dp[i][j][f]<0)continue;
                    dp[i+1][j][f+(s1[i]==s2[0])]=max(dp[i+1][j][f+(s1[i]==s2[0])],dp[i][j][f]+((s1[i]==s2[1])?f:0));
                if(j<k){ //修改需要特判相等
                    dp[i+1][j+1][f+1]=max(dp[i+1][j+1][f+1],dp[i][j][f]+((s2[0]==s2[1])?f:0));
                    dp[i+1][j+1][f+(s2[0]==s2[1])]=max(dp[i+1][j+1][f+(s2[0]==s2[1])],dp[i][j][f]+f);    
                }
          } 
   }   
   int ans=0;
   for(int i=0;i<=k;++i)
      for(int j=0;j<=n;++j)
        ans=max(dp[n][i][j],ans);
   printf("%d\n",ans); 
   return 0; 
}
