#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100],b[100]; 
void print()
{
	for(int i=1;i<=n;++i)
	cout<<b[i]<<" ";
	putchar('\n');
}
void dfs(int k)
{
	if(k==n+1)
	print();
	else for(int i=1;i<=n;++i)//对于1~n的数的枚举 
	{
		if(!a[i])
		{
			a[i]=1;
			b[k]=i;
		    dfs(k+1);
	    	a[i]=0;
		} 
	} 
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}
