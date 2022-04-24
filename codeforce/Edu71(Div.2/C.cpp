#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#define ll long long
using namespace std;
char s[200005];
ll dp[200005][2];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    { 
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        scanf("%s",s+1);
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=b;
        for(int i=1;i<=n;++i)
        {
           for(int j=0;j<2;++j)
           {
              if(s[i]=='1')
              {
                 dp[i][1]=min(dp[i][1],dp[i-1][1]+2*b+a);
              } 
              else 
              {
                 dp[i][1]=min(dp[i][1],min(dp[i-1][0]+2*a+2*b,dp[i-1][1]+2*b+a));
                 dp[i][0]=min(dp[i][0],min(dp[i-1][0]+a+b,dp[i-1][1]+2*a+b));
              }
           } 
        }
        cout<<dp[n][0]<<"\n";
    }
    return 0;
}
