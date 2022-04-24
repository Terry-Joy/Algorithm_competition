#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct Node{
	int s,a,id;
	bool operator<(const Node&x)const{
		if(a==x.a)return s<x.s;
		return a<x.a;
	}
}h[maxn];
int S[maxn<<1],cnt,dp[maxn];
int main(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>h[i].s>>h[i].a;
		if(h[i].s<d){
			i--;n--;
			continue;
		}
		S[++cnt]=h[i].s;
		S[++cnt]=h[i].a;
		h[i].id=i;
	}
	sort(S+1,S+1+cnt);
	int m=unique(S+1,S+1+cnt)-(S+1);
	for(int i=1;i<=n;++i){
		h[i].s=lower_bound(S+1,S+1+m,h[i].s)-S;
		h[i].a=lower_bound(S+1,S+1+m,h[i].a)-S;
	}
	sort(h+1,h+1+n);
	int now=1,st=0;
	d=lower_bound(S+1,S+1+m,d)-S;
	while(h[now].a<=d){
		if(h[now].s>=d)
			st++;
		now++;
	}
	dp[d]=st;
	tr.update()
	for(int i=1;i<=n;++i){

	}
	return 0;
}