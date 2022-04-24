#include<cstdio>
using namespace std;
int gcd(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}
	if(y==0)
	return x;
	gcd(y,x%y);
}
int main()
{
	long long n,a,b,k,temp;
	scanf("%lld",&n);
	while(n--)
	{	
		scanf("%lld",&k);
		temp=1;
		while(k--)
		{
		
		scanf("%lld",&a);
		temp=temp*a/gcd(a,temp);
		}
		printf("%lld\n",temp);
	}
	return 0;
}
