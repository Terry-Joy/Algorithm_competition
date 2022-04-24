#include<iostream>
using namespace std;
int f[1010][2];
int main()
{
	int n;
	cin>>n;
	f[1][1]=1;
	f[1][0]=9;
	for(int i=2;i<=n;++i)
	{
	int x=f[1][0];
	if(i==n)
	x--;
	f[i][0]=(f[i-1][0]*x+f[i-1][1])%12345;
	f[i][1]=(f[i-1][1]*x+f[i-1][0])%12345;
	}
	cout<<f[n][0];
	return 0;
	
} 
