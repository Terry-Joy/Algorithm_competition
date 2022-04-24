#include<iostream>
using namespace std;
using ll=long long;
int main(){
	//freopen("6.in","r",stdin);
	//freopen("6.out","w",stdout);	
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		ll l=1,r=1e9+1;
		while(l<r){
			ll mid=l+r>>1;
			ll A=mid*c-a,B=mid*d-b;
			if(A>=0&&A<=B){
				r=mid;
			}else 
				l=mid+1;
		} 
		if(r==1e9+1)cout<<-1<<"\n";
		else cout<<r*d-b<<"\n";
	}
	return 0;
}