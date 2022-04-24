#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int a[25][25];
int dp[22][1<<20];//当前第i个点，20个点的经过状态
int main()
{
   int n;
   cin>>n;
   memset(dp,0x3f,sizeof(dp));
   dp[1][1]=0;
   for(int i=1;i<=n;++i)
       for(int j=1;j<=n;++j)
           cin>>a[i][j];
   for(int i=1;i<(1<<n);++i)
   {
       for(int j=1;j<=n;++j)
       {
          if(i&(1<<j-1))
          {
             for(int k=1;k<=n;++k)
             {
                if(!(i&(1<<k-1)))
                    dp[k][i|(1<<k-1)]=min(dp[k][i|(1<<k-1)],dp[j][i]+a[j][k]); 
             } 
          } 
       } 
   } 
   cout<<dp[n][(1<<n)-1]<<endl;
   return 0; 
}
