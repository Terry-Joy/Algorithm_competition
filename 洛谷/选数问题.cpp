#include<cstdio>
#include<iostream> 
using namespace std;
int n,k,ans=0,number[30];
bool is_prime(int x)
{
	for(int i=2;i*i<=x;++i)
	if(x%i==0)
	return false;
	return true;
}
void dfs(int x,int y,int z)//x表示当前第几层，y表示选了几个数，z表示总和 
{
	if(x>n)
	return;
	if(y==k)
	if(is_prime(z))
	{
		ans++;
		return;
	}
	dfs(x+1,y,z);
	dfs(x+1,y+1,z+number[x]);
	return;	
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	scanf("%d",&number[i]);
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
