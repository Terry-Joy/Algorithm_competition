#include<cstdio>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	stack<int>a;
	string c;
	cin>>c;
	int m=0,len=c.length()-1;
	for(int i=0;i<len;++i)
	{
		if(c[i]>='0'&&c[i]<='9')
		m=m*10+c[i]-'0';
		else if(c[i]=='.')
		{
			a.push(m);	
			m=0;
		}
		else 
		{
			int x=a.top();
			a.pop();
			int y=a.top();
			a.pop();
			if(c[i]=='+')
			a.push(x+y);
			else if(c[i]=='-')
			a.push(y-x);
			else if(c[i]=='*')
			a.push(x*y);
			else if(c[i]=='/')
			a.push(y/x);	
		}
	}
	cout<<a.top();
	return 0;
}
