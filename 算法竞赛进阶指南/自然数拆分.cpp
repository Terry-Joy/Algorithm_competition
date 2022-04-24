#include<iostream>
#include<cstdio>
#include<cstring>
int f[4010];
const unsigned int mod=2147483648;
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	f[0]=1;	
	for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j)
		f[j]=(f[i]+f[j-i])%mod;
	cout<<(f[n]>0?f[n]-1:mod)<<endl;
	return 0;
} 
