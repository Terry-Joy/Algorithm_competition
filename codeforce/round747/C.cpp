#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
int t,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	string s;
	char c;
	while(t--){
		vector<int>pos;
		cin>>n>>c;
		cin>>s;
		int cnt=0,num=0;
		for(int i=0;i<s.length();i++){
			if(s[i]!=c)cnt++;
			else pos.eb(i+1);
		}
		for(int&v:pos){
			bool f=1;
			for(int i=v;i<=s.length();i+=v){
				if(s[i-1]!=c){
					f=0;break;
				}
			}
			if(f){
				num=v;break;
			}
		}
		if(!cnt){
			cout<<"0\n";
		}else{
			if(num)cout<<1<<"\n"<<num<<"\n";
			else{
				cout<<2<<"\n"<<n-1<<" "<<n<<"\n";
			}
		}
	}
	return 0;
}