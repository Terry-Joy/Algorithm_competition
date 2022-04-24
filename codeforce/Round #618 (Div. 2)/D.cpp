#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int x[100100],y[100100];
	for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	if(n&1)
	{
		printf("NO\n");
		return 0;
	}
	int X=x[0]+x[n/2];
	int Y=y[0]+y[n/2];
	for(int i=0;i<n/2;i++)
	{
		if((x[i]+x[n/2+i]!=X)||(y[i]+y[n/2+i]!=Y))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
