#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
struct Node{
	int l,r;
	bool operator<(const Node&a)const{
		return r<a.r;
	}
}a[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+n);
	int nowl=a[1].l,nowr=a[1].r;
	int ans=1;
	for(int i=2;i<=n;++i){
		if(a[i].l<=nowr)continue;
		else{
			ans++;
			nowl=a[i].l;nowr=a[i].r;
		}
	}
	cout<<ans<<"\n";
	return 0;
}