#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,r,x,s,k;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		k=(n-m)/(m+1);
		l=(n-m)%(m+1);
		s=((n+1)*n/2)-((k+1)*k/2)*(m+1-l)-l*(k+1)*(k+2)/2;
		cout<<s<<endl;
	}
	return 0;
}

