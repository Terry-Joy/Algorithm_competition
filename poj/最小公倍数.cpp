#include<iostream>
using namespace std;
int gcd(int x,int y)
{
	if(y==0)return x;
	gcd(y,x%y);
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int k=n*m/gcd(n,m);
		cout<<k<<endl;
	}
	return 0;
}
