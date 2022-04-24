#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,l,r;
	cin>>n;
	cin>>l>>r;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		ll b1=(x>l)?0:(l+x-1)/x;
		ll b2=(y>r)?0:(r+y-1)/y;
		if(x>l&&y>r)
			l=x,r=y;
		else{
			l=max(b1,b2)*x;
			r=max(b1,b2)*y;
		}
	}
	cout<<l+r<<"\n";
	return 0;
}