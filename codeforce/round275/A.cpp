#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ll l,r;
	cin>>l>>r;
	if(r-l+1<3){
		cout<<-1<<'\n';
	}else if(r-l+1==3){
		if(l&1)cout<<-1<<"\n";
		else cout<<l<<" "<<l+1<<" "<<r;
	}else{
		ll st=(l&1)?l+1:l;
		cout<<st<<" "<<st+1<<" "<<st+2;
	}
	return 0;
}