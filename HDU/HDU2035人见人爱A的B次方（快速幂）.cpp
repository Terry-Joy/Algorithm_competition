#include<iostream>
using namespace std;
int digit[3];
long long mi(long long a,long long b,long long mode)
{
	long long sum=1;
	a=a%mode;
	while(b>0)
	{
		if(b%2==1)
		sum=sum*a%mode;
		b/=2;
		a=a*a%mode;
	}
	return sum;
}
int main()
{
	int a,b;
	while(cin>>a>>b&&(a!=0||b!=0))
	{
			cout<<mi(a,b,1000)<<endl;	
	}
	return 0;
}
