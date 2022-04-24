#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,t,a[maxn];
int main(){
	cin>>t;
	int T=0;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=0;
		for(int i=3;i<=n;++i)ans^=max(a[i]-2,0);
		printf("Case %d: %d\n",++T,ans);
	}
	return 0;
}