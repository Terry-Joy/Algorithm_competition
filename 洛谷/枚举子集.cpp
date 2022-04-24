#include<cstdio>
#include<iostream> 
using namespace std;
int que[20],ans=1,n;
void output()
{
	for(int i=1;i<=ans;++i)
	cout<<que[i]<<" ";
	putchar('\n');
}
void dfs(int x)
{
	if(x==n+1)
	{
	output();
	return;
	}
	dfs(x+1);//²»Ñ¡ 
	que[++ans]=x;
	dfs(x+1);
	--ans;
}
int main()
{
	
	scanf("%d",&n);
	dfs(1);
	return 0;
	
}
