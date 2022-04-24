#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+5;
int n,k;
vector<int>ans;
bool v[maxn];
int main(){	
	cin>>n>>k;	
	for(int i=1;i+k<=n;++i){
		if(v[i])continue;
		for(int j=i;j<=n;j+=k){
			if(!v[j]){
				ans.pb(j);v[j]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(!v[i])ans.pb(i);
	}
	for(int i=0;i<ans.size()-1;++i){
		cout<<ans[i]<<' ';
	}
	cout<<ans[ans.size()-1];
	return 0;
}