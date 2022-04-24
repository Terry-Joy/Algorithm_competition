//o(n)筛2~n每个数的欧拉函数 
void primes()
{
	memset(v,0,sizeof(v));
	v[1]=v[0]=1;phi[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!v[i])phi[i]=i-1,prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=n;++j)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				phi[prime[j]*i]=phi[i]*prime[j]
				break;
			} 
			else phi[prime[j]*i]=phi[prime[j]]*phi[i];
		}
	}	
}
