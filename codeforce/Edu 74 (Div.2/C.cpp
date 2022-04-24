#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int h,n;
		scanf("%d%d",&h,&n);
		int p[200010];
		memset(p,0,sizeof(p));
		int i,temp,now=h;
		for(i=n;i>=1;i--)
		{
			scanf("%d",&p[i]);
		}
		int ans=0;
		p[0]=0;
		for(i=n;i>=0;)
		{
			if(h<=2)
			break;
			if(h==p[i])
			{
				i--;
			}
			if(h-1>p[i])
			{
				h=p[i]+1;
			}
			if(h-1==p[i])
			{
				if(h-2==p[i-1])
				{
					h-=2;i-=2;
				}
				else if(h-2>p[i-1])
				{
					ans++;h-=2;i--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

