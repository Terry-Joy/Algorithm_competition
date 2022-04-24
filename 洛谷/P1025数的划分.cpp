#include<cstdio> 
using namespace std;
int n,k,ans=0;
void dfs(int x,int sum,int last)
{
	if(x==k)
	{
	if(sum==n)
		ans++;
		return;
	}
	else 
	{
		for(int i=last;sum+i*(k-x)<=n;++i)
		dfs(x+1,sum+i,i);
	}
}
int main()
{
	scanf("%d%d",&n,&k); 
	dfs(0,0,1);
	printf("%d",ans);
	return 0;
}
