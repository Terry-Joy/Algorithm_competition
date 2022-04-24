#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

int k,a[6];
int main()
{
	while(scanf("%d",&k)&&k)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=k;++i)scanf("%d",&a[i]);
		ll dp[a[1]+1][a[2]+1][a[3]+1][a[4]+1][a[5]+1];
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0][0]=1;
		for(int i=0;i<=a[1];++i)
			for(int j=0;j<=a[2];++j)
				for(int k=0;k<=a[3];++k)
					for(int l=0;l<=a[4];++l)
						for(int p=0;p<=a[5];++p)
						{
							if(i+1<=a[1])
								dp[i+1][j][k][l][p]+=dp[i][j][k][l][p];
							if(j+1<=a[2]&&j<i)
								dp[i][j+1][k][l][p]+=dp[i][j][k][l][p];
							if(k+1<=a[3]&&k<j)
								dp[i][j][k+1][l][p]+=dp[i][j][k][l][p];
							if(l+1<=a[4]&&l<k)
								dp[i][j][k][l+1][p]+=dp[i][j][k][l][p];
							if(p+1<=a[5]&&p<l)
								dp[i][j][k][l][p+1]+=dp[i][j][k][l][p];
						} 
						printf("%lld\n",dp[a[1]][a[2]][a[3]][a[4]][a[5]]);
	}
	return 0;
}
