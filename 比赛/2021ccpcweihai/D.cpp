#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	int n=strlen(s+1),q;
	vector<int>nxt(n+1,0);
	for(int i=2,j=0;i<=n;++i){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
	}
	vector<int>sum(n+1,0);
	int now=nxt[n];
	while(now){
		sum[now]++;
		now=nxt[now];
	}
	for(int i=1;i<=n;++i)sum[i]+=sum[i-1];
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		x=min(x-1,n-x);
		cout<<sum[x]<<"\n";
	}
	return 0;
}