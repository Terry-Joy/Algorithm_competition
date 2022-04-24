#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>ans(n+1,-1);
	for(int i=1;i<=n;++i){
		cout<<"?";
		for(int j=1;j<n;++j){
			cout<<" "<<i;
		}
		cout<<" "<<n<<endl;
		int x;
		cin>>x;
		if(x){
			ans[n]=i;
			break;
		}
	}
	if(ans[n]==-1)ans[n]=n;
	for(int i=1;i<=n;++i){
		cout<<"?";
		for(int j=1;j<n;++j)cout<<" "<<ans[n];
		cout<<" "<<i<<endl;
		int x;
		cin>>x;
		if(x)ans[x]=i;
	}
	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}