#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a;
	while(cin>>n&&n)
	{
	 int n1=n;
	int s=0,sum=0;
	while(n--)
	{	
		cin>>a;
		
		if(a>s)
		{
		sum+=6*(a-s);
		s=a;
		}
		if(a<s)
		{
			sum+=4*(s-a);
			s=a;
		}
		
		if(a=s);
		
	}
	sum+=n1*5;
	cout<<sum<<endl;
	}
}
