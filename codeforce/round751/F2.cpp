#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct Node{
	int s,a;
}h[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>h[i].s>>h[i].a;
		if(h[i].s<d){
			i--;n--;
			continue;
		}
	}
	sort(h+1,h+1+n,[&](Node x,Node y){
		if(max(x.s,x.a)==max(y.s,y.a))return x.s<y.s;
		return max(x.s,x.a)<max(y.s,y.a);
	});
	int now=d,ans=0;
	for(int i=1;i<=n;++i){
		if(h[i].s>=now){
			ans++;
			now=max(now,h[i].a);
		}
	}
	cout<<ans;
	return 0;
}