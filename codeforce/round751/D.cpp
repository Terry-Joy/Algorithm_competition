#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
queue<int>q;
int main(){
	int n;
	cin>>n;
	vector<int>a(n+1,0),b(n+1,0),fa(n+1,0);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	q.push(n);
	int mn=n;
	while(!q.empty()){
		int x=q.front();q.pop();
		int y=x+b[x];
		if(y-a[y]<=0){
			vector<int>ans;
			ans.eb(0);
			int i=x;
			while(i!=n){
				ans.eb(i);
				i=fa[i];
			}
			cout<<ans.size()<<"\n";
			reverse(ans.begin(),ans.end());
			for(auto&u:ans){
				cout<<u<<" ";
			}
			return 0;
		}
		for(int i=mn-1;i>=y-a[y];--i){
			fa[i]=x;
			q.push(i);
		}
		mn=min(mn,y-a[y]);
	}
	cout<<-1;
	return 0;
}