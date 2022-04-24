//朴素算法 
for(int i=1;i<=n;++i){
		for(int j=M;j>=w[i];--j)
			for(int k=1;k<=num[i];++k){
				if(k*w[i]>j)break;
					dp[j]=max(dp[j],dp[j-k*w[i]]+v[i]*k);
			}
	}

for(int i=1;i<=n;++i)
{
	if(c[i]*num[i]>=V)			//完全背包常数优化 
	{
		for(int v=c[i];v<=V;++v)
		  dp[v]=max(dp[v],dp[v-c[i]]+w[i]);
		continue;
	}
	for(int k=1;num[i];k<<=1)
	{
		if(num[i]<k)k=num[i];
		num[i]-=k;
		int a=k*c[i],b=k*w[i];
		for(int v=V;v>=a;--v)
			dp[v]=max(dp[v-a]+b,dp[v]);
	}
}
