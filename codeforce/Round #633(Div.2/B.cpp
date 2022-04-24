#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int a[100010],dp[100010][2];
ll lg[34];
vector<int>is;
int main()
{
   int t;
   scanf("%d",&t);
   lg[1]=1;
   for(int i=2;i<=33;++i)
        lg[i]=(lg[i-1]<<1);     
   while(t--)
   {
       int n;
       scanf("%d",&n);
       for(int i=1;i<=n;++i)
           dp[i][1]=dp[i][0]=inf;
       dp[1][1]=dp[1][0]=0;
       for(int i=1;i<=n;++i)
           scanf("%d",&a[i]);
       int k=1,f=1;
       for(int i=2;i<=n;++i)
       {
          if(a[i-1]>a[i])
          { 
             while(a[i-1]>a[i])
             { 
                a[i]+=lg[k];
                dp[i][1]=min(dp[i-1][1],dp[i-1][0])+1;
                k++;
             }
             dp[i][0]=inf;
          }
          else
          { 
              dp[i][0]=min(dp[i-1][1],dp[i-1][0]);
          }
       }
       cout<<dp[n][0]<<" "<<dp[n][1];
       int ans=min(dp[n][0],dp[n][1]);
       printf("%d\n",ans);
   }
   return 0; 
}

