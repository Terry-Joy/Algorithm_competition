#include<iostream>
#include<cstring>
using namespace std;
int a[20];
int f[20];int ans=0;
int n,i=1;
bool is_prime(int x)
{
	for(int i=2;i*i<=x;++i)
	if(x%i==0)return false;
	return true;
}
void show()
{
	if(i!=n-1)
	{
	for(int i=1;i<n;++i)
	cout<<a[i]<<" ";
	cout<<a[n];
	cout<<endl; 
	}
	else 
	{
		for(int i=1;i<n;++i)
	cout<<a[i]<<" ";
	cout<<a[n];
	}
}
void dfs(int x)
{
	if(x==n+1&&is_prime(a[1]+a[x-1]))
	     show();
	else 
	{
		for(int i=2;i<=n;++i)
		if(is_prime(i+a[x-1])&&!f[i])
		{
			f[i]=1;
			a[x]=i;
			dfs(x+1);
			f[i]=0; 
		}
	}
}
int main()
{
	
	while(cin>>n)
	{
		if(i>=2)cout<<endl;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		a[1]=1;f[1]=1;
		cout<<"Case "<<i<<":"<<endl;
	dfs(2);
	++i;
	}
} 
