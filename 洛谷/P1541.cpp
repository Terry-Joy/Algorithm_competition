#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dp[2][42][42][42],a[360],b[5];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]);
   int x;
   for(int i=1;i<=m;++i)
   {
      scanf("%d",&x);
      b[x]++; 
   }
   dp[0][0][0][0]=a[1];
   for(int i=0;i<=b[1];++i) 
      for(int j=0;j<=b[2];++j)
          for(int k=0;k<=b[3];++k)
              for(int f=0;f<=b[4];++f)
              {
                 int t=a[i+2*j+3*k+4*f+1];
                 if(i)dp[i&1][j][k][f]=max(dp[(i-1)&1][j][k][f]+t,dp[i&1][j][k][f]);
                 if(j)dp[i&1][j][k][f]=max(dp[i&1][j-1][k][f]+t,dp[i&1][j][k][f]);
                 if(k)dp[i&1][j][k][f]=max(dp[i&1][j][k-1][f]+t,dp[i&1][j][k][f]);
                 if(f)dp[i&1][j][k][f]=max(dp[i&1][j][k][f-1]+t,dp[i&1][j][k][f]); 
              }
   printf("%d\n",max(dp[0][b[2]][b[3]][b[4]],dp[1][b[2]][b[3]][b[4]]));
   return 0; 
}
