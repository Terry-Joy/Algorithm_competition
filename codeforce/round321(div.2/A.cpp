#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>a(n+2,0);
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=1,nowans=1;
	for(int i=2;i<=n+1;++i){
		if(a[i]>=a[i-1]){
			nowans++;
		}else{
			ans=max(ans,nowans);
			nowans=1;
		}
	}
	cout<<ans;
	return 0;
}