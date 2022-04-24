#include<iostream>
using namespace std;
int n,x;
long long solve(int m)
{
	int rest=0;
	while(m)
	{
		rest+=m;
		m/=x;
	}
	return rest;
}
int main() 
{
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>x;
		int l=2,r=n;
		int ans;
		while(l<r)
		{
			int m=(l+r)/2;
			if(solve(m)>=n)
			{
				ans=m;r=m;
			}
			else l=m+1;
		}
		cout<<ans<<endl;
	}
}
