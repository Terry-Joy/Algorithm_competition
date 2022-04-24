#include<cstdio>
#include<cstring>
using namespace std;
const int max_1=10010;
const int max_2=1e8+7;
int dp[max_1],num[max_1];
char c[max_1];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c);
		int n=strlen(c);
		memset(num,0,sizeof(num));
		for(int i=0;i<n;++i)
		num[i+1]=c[i]-'0';
		memset(dp,0,sizeof(dp));
		long long ans=0;
		for(int i=0;i<=num[1];++i)//枚举dp[1] 
		{
			dp[1]=i;
			if(i>2)break;
			int j;
			for(j=2;j<=n;++j)
			{
			int k=num[j-1]-dp[j-1]-dp[j-2];
			if(k>2||k<0)//判断是否可行 
			break;
			dp[j]=k;
			}
			if(j<=n)continue;//加入方案不对，重新判断另一个方案 
			if(dp[n]+dp[n-1]!=num[i])continue;//判断最后两列是否满足 
			long long sum=1;
			for(int i=1;i<=n;++i)
			{
			if(dp[i]==0||dp[i]==2)
			sum*=1;
			else if(dp[i]==1)
			sum*=2;
			sum%=max_2;
			}
			ans+=sum;
			ans%=max_2;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
