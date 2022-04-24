#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a,b;
	char c;
	cin>>n;
	while(n--)
	{
		cin>>c>>a>>b;
		if(c=='+')
		cout<<a+b<<endl;
		if(c=='-')
		cout<<a-b<<endl;
		if(c=='*')
		cout<<a*b<<endl;
		if(c=='/')
		{
		if(a/b==a*1.0/b)
		cout<<a/b;
		else printf("%.2lf\n",a*1.0/b);
		}
		
	}
	return 0;
}
