#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
int n,m,a[200005];
bool is(int mid)
{
	int f=mid;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=ans)
		{
			ans++;
		}
		else if(f) 
		{
			ans++;
			f--;
		}
		if(ans==m)return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		 scanf("%d",&a[i]);
	int l=0,r=m+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(is(mid))
			r=mid;
		else l=mid +1;
	}
	printf("%d",r); 
	return 0;
}
 
