#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
ll a,b,p;
ll mypow(ll a,ll b,ll c){
 	ll ans=1%p;
 	while(b){
 		if(b&1)ans=ans*a%c;
 		a=a*a%c;b>>=1;
 }	
 return ans;
} 
int main()
{
	cin>>a>>b>>p;
	cout<<mypow(a,b,p);
	return 0;
} 
