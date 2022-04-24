#include<iostream>
#include<cstdio>
using namespace std;
bool v[15];
int p[15],n;
void dfs(int x)
{
	if(x==n+1){
	for(int i=1;i<=n;++i)
		printf("%d ",p[i]);
	putchar('\n');
	return;
	} 
	for(int i=1;i<=n;++i)
	{
		if(v[i])continue;
		p[x]=i;
		v[i]=1;
		dfs(x+1);
		v[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
} 
