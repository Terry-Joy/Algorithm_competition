#include<iostream>
#define ll long long 
using namespace std;
ll a,b,p;
ll mul(ll a,ll b,ll p){
	ll ans=0;
	while(b){
		if(b&1)ans=(ans+a)%p;
		a=a*2%p;b>>=1;
	}
	return ans;
} 
int main()
{
	cin>>a>>b>>p;
	cout<<mul(a,b,p);
	return 0;
}
