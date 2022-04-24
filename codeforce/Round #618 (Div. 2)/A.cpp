#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t,n,a[110]; 
int main()	
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,sum=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)
			{
				ans++;
				a[i]++;	
			}
		}
		for(int i=1;i<=n;++i)
			sum+=a[i];
		if(sum==0)ans++;
		printf("%d\n",ans);
	}
	return 0;
} 
