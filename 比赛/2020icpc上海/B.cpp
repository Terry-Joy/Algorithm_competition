#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<string>a(n),b(n);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	int sum1=0,sum2=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			sum1+=(b[i][j]==a[i][j]);
			sum2+=(b[i][j]!=a[i][j]);
		}
	for(int i=0;i<n;++i){
		for(auto u:a[i]){
			if(sum1>sum2){
				cout<<u;
			}else{
				cout<<((u=='X')?'.':'X');
			}
		}
		cout<<'\n';
	}
	return 0;
}