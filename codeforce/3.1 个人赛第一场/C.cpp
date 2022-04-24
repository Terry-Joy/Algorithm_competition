#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
struct node
{
	int a,b;
}v[200005];
bool cmp1(node x,node y)
{
	return x.b<y.b;
	if(x.b==y.b)return x.a>y.a;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&v[i].a,&v[i].b);
	}
	sort(v+1,v+1+n,cmp1);
	int k[200005],cnt=1;
	k[1]=v[1].b;
	for(int i=2;i<=n;++i)
	{
		if(v[i].a<=k[cnt]&&v[i].b>=k[cnt])
			continue;
		else {
			k[++cnt]=v[i].b;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
		printf("%d ",k[i]);
	return 0;
}
 
