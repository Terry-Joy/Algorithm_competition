#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n&1){
			n--;
			int now1=n/2,now2=n/2;
			while(__gcd(now1,now2)!=1){
				now1--;
				now2++;
			}
			cout<<now1<<" "<<now2<<" "<<1<<'\n';
		}else{
			n--;
			cout<<n/2<<" "<<(n+1)/2<<" "<<1<<"\n";
		}
	}
	return 0;
}