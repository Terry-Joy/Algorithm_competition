#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int n1=n,m1=m;
	int s1=0,s2=0;
	while(n1!=0&&m1!=0)
	{
		s1+=n1*m1;
		n1--;m1--;
	}
	s2=(1+n)*(1+m)*m*n/4-s1;
	cout<<s1<<" "<<s2;
	return 0;
} 
