#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[610][610],dis[310][310];
int loc[610],n,m,k;
int main()
{
   scanf("%d%d%d",&n,&m,&k);
   for(int i=1;i<=n;++i){ 
      for(int j=1;j<=n;++j)dis[i][j]=1e18;
      dis[i][i]=0;
   } 
   for(int i=1;i<=m;++i){ 
       int a,b,c;
       scanf("%d%d%d",&a,&b,&c);
       dis[a][b]=dis[b][a]=min(dis[a][b],1ll*c); 
   }
   for(int i=1;i<=k;++i){ 
       int a,b;
       scanf("%d%d",&a,&b);
       loc[2*i-1]=a,loc[2*i]=b; 
   }
   for(int k=1;k<=n;++k)
       for(int i=1;i<=n;++i)
           for(int j=1;j<=n;++j)
               dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
   for(int i=0;i<=2*k;++i)
      for(int j=0;j<=n;++j)
         dp[i][j]=1e18;
   dp[0][1]=0;
   loc[0]=1;
   for(int i=1;i<=2*k;++i){ 
       for(int j=1;j<=n;++j){ 
           dp[i][j]=min(dp[i][j],dp[i-1][j]+min(dis[loc[i-1]][loc[i]],dis[j][loc[i]]));
           for(int k=1;k<=n;++k){ 
              dp[i][k]=min(dp[i][k],dp[i-1][j]+min(dis[j][k]+dis[k][loc[i]],dis[loc[i-1]][k]+dis[j][loc[i]]));
           }
       }
   }
   ll ans=1e18;
   for(int i=1;i<=n;++i)
       ans=min(ans,dp[2*k][i]);
   printf("%lld\n",ans);    
   return 0; 
}
