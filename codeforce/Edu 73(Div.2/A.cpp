#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,a;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a);
			if(a<=2048)
				ans+=a;
			else 
				continue;		
		}
		if(ans>=2048)
			printf("YES\n");
		else 
			printf("NO\n");
	} 
	return 0;
} 
