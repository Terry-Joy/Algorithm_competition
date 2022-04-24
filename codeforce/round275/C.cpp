#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int l=1,r=n;
	for(int i=1;i<=k;++i){
		if(i&1)cout<<l++<<" ";
		else cout<<r--<<" ";
	}
	if(k&1){
		for(int i=l;i<=r;++i)cout<<i<<" ";
	}else
		for(int i=r;i>=l;--i)cout<<i<<" ";
	return 0;
}