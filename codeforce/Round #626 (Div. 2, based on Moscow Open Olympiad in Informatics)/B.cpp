#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int maxn=8e4;
int factor[maxn],a[40010],b[40010];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int f=0;
	for(int i=1;i*i<=k;++i){
		if(k%i==0){
			factor[++f]=i;
			if(i!=k/i)factor[++f]=k/i;
		}
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int j=1;j<=m;++j)
		scanf("%d",&b[j]);
	ll ans=0;
	for(int i=1;i<=f;++i)
	{
		ll cnt=0,x=0,y=0;
		for(int j=1;j<=n;++j)
		{
			if(a[j]==1)cnt++;
			else cnt=0;
			if(cnt==factor[i])cnt--,x++;
		}	
		cnt=0;
		for(int j=1;j<=m;++j)
		{
			if(b[j]==1)cnt++;
			else cnt=0;
			if(cnt==k/factor[i])cnt--,y++;
		}
		ans+=x*y;
	}
	printf("%lld\n",ans);
	return 0;
} 
