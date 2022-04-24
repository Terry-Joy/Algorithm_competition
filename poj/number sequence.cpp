#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int nex[maxn],k,n,m;
int t[maxn],s[10010];
void KMP(int m)
{
	int j;
	nex[1]=j=0;
	for(int i=2;i<=m;++i)
	{
		while(j>0&&s[i]!=s[j+1])j=nex[j];
		if(s[i]==s[j+1])nex[i]=++j;
	}
}
int main()
{
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",&t[i]);
		for(int i=1;i<=m;++i)
			scanf("%d",&s[i]);
		KMP(m);
		int j=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			while(j>0&&t[i]!=s[j+1])j=nex[j];
			if(t[i]==s[j+1]) j++;
			if(j==m)ans++;
			if(ans>0)
			{
				printf("%d\n",i-m+1);
				break;
			}
		}
		if(ans==0)printf("-1\n");
	}
	return 0;
}

