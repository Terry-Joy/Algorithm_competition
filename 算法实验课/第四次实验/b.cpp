#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct Node{
	int l,r;
	bool operator<(const Node&a)const{return l<a.l;}
}a[maxn];
int main(){
	int L,M;
	cin>>L>>M;
	int ans=L+1;
	for(int i=1;i<=M;++i){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+1+M);
	a[M+1].l=1000000000;
	int nowl=a[1].l,nowr=a[1].r;
	for(int i=2;i<=M+1;++i){
		if(a[i].l>nowr){
			ans-=(nowr-nowl+1);
			nowl=a[i].l,nowr=a[i].r;
		}else{
			nowr=max(nowr,a[i].r);
		}
	}
	cout<<ans;
	return 0;
}