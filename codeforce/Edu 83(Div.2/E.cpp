#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[510][510],dp[520][520];
int main()
{ 
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   for(int j=i+1;j<=n;++j)
   {
		dp[i][j]=j-i+1;
	}
   for(int i=1;i<=n;++i)
   	{
	   scanf("%d",&a[i][i]);
	   dp[i][i]=1;
	}
   
   for(int len=2;len<=n;++len)
   {
   	   for(int l=1;l+len-1<=n;++l)
   	   {
		   int r=l+len-1;
		   for(int k=l;k<r;++k)
		   {
		   		dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
		   		if(a[l][k]==a[k+1][r]&&dp[l][k]==1&&dp[k+1][r]==1)
		   		{
					dp[l][r]=1;
					a[l][r]=a[l][k]+1;
				}
		   }
	   }	  
	} 
	printf("%d",dp[1][n]);
   return 0; 
}
