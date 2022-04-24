#include<iostream>
#include<algorithm>
using namespace std;
int k[100010];
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;++i)
	cin>>k[i];
	sort(k,k+n);
	if(n%2==0){
	for(int i=1;i<n;++i)
	{
		if(k[i]%2==0)
		sum+=k[i]-1;
		else sum+=k[i];
	}
	}
	else 
	for(int i=0;i<n;++i)
	{
		if(k[i]%2==0)
		sum+=k[i]-1;
		else sum+=k[i];
	}
	cout<<sum;
	return 0;
} 
