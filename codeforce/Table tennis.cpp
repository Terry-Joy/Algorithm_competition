#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int table[510];
int main()
{
	ll n,k,sum=0;
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;++i)
	scanf("%d",&table[i]);
	ll ans=table[0];
	for(int i=1;i<n;++i)
	{
		if(table[i]>ans)
		{
			sum=1;
			ans=table[i];
		}
		else
			sum++;
		if(sum==k)
		{
		cout<<ans<<"\n";
		return 0;
		}
	}
	if(sum<k)
	cout<<ans<<"\n";
		return 0;
} 
