#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int x[maxn],n,L,q,f[maxn][20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>x[i];
	cin>>L;
	for(int i=1;i<=n;++i){
		int id=upper_bound(x+i,x+1+n,x[i]+L)-x-1;
		f[i][0]=id;
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i<=n;++i){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	cin>>q;
	int a,b;
	for(int i=1;i<=q;++i){
		cin>>a>>b;
		if(a>b)swap(a,b);
		int now=0;
		for(int j=19;j>=0;--j){
			if(f[a][j]<b){
				a=f[a][j];
				now+=(1<<j);
			}
		}
		cout<<now+1<<"\n";
	}
	return 0;
}