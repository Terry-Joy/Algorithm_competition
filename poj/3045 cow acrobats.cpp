#include<iostream>
#include<algorithm>
using namespace std;
struct cow{
	int wi,si,ci;
};
cow a[50010];
bool cmp1(cow x,cow y)
{
	return x.ci<y.ci; 
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
	cin>>a[i].wi>>a[i].si;
	a[i].ci=a[i].wi+a[i].si;
	}
	sort(a,a+n,cmp1);
	int ans=-a[0].si,num=0;
	if(n==1)
	{
	cout<<ans<<endl;
	return 0;
	}
	for(int i=0;i<n-1;++i)
	{
		 num+=a[i].wi;
		 ans=max(ans,num-a[i+1].si);
	}	
	cout<<ans<<endl;
	return 0;
} 
