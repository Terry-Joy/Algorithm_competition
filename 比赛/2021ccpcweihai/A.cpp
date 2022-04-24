#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,u,v;
	cin>>n;
	vector<int>deg(n+1,0);
	for(int i=1;i<n;i++){
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(deg[i]>=4){
			ans=-1;
			break;
		}
		else if(deg[i]<=2)
			ans++;
	}
	cout<<(ans==-1?0:ans);
	return 0;
}