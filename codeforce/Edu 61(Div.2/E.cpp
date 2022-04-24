#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
ll dp[12][8*840+10];
ll num[9];
int main()
{ 
    ll lcm=840;
    ll w;
    scanf("%lld",&w);
    for(int i=1;i<=8;++i)
        scanf("%lld",&num[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=8;++i)
    {
       for(int j=0;j<8*lcm;++j)
       {
          ll cnt=min(num[i],lcm/i-1);
          for(int k=0;k<=cnt;++k)
          {
             if(j-k*i>=0&&dp[i-1][j-k*i]!=-1)
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*i]+(num[i]-k)/(lcm/(ll)i)); 
          } 
       }
    }
      ll ans=0;
      for(ll i=0;i<8*lcm;++i)
      { 
         if(dp[8][i]!=-1||i<=w)
            ans=max(ans,i+lcm*min(dp[8][i],(w-i)/lcm));
      }
    
    printf("%lld\n",ans);
    return 0; 
}
