#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#define ll long long 

using namespace std;
const int maxn=110;
ll dp[maxn],map[maxn][maxn];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   memset(dp,0,sizeof(dp));
   for(int i=1;i<=m;++i)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      map[a][b]++,map[b][a]++; 
   }
   dp[0]=1;
   bool flag=0;
   for(int i=1;i<=n;++i)
       for(int j=0;j<i;++j)
       { 
           flag=1;
           if(map[i][j])continue;
           for(int k=j+1;k<i;++k)
           {
              if(map[i][k]||map[j][k])continue;
              else { 
                flag=0;
                break;
              } 
           }
           dp[i]+=flag*dp[j];
       }
   ll ans=0;
   for(int i=1;i<=n;++i)
   {
      flag=1;
      for(int j=i+1;j<=n;++j)
      { 
         if(!map[i][j]) 
             flag=0;
      }
      ans+=flag*dp[i];
   }
   printf("%lld\n",ans);
   return 0; 
}
