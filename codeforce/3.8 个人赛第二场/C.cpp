#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long 
using namespace std;
int t,n;
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&n);
			ll ans=0,k=0;
			for(int i=2;i<=sqrt(n);++i)
			{
				if(n%i==0)
				{
					while(n%i==0){
						ans+=i;k++;n/=i;
					}
				}
			}
			if(n>1)
				{
					ans+=n;k++;
				}
			printf("%lld\n",ans-k+1);	
	}
	return 0;
} 
