#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
bool v[maxn];
void init(){
	v[1]=v[0]=1;
	for(int i=2;i<maxn;++i){
		if(v[i])continue;
		for(int j=2*i;j<maxn;j+=i){
			v[j]=1;
		}
	}
}
int t,a,b,d[maxn];
unordered_map<int,int>mp;
void bfs(){
	memset(d,-1,sizeof(d));
	d[a]=0;
	queue<int>q;
	q.push(a);
	while(!q.empty()){
		int x=q.front();q.pop();
		int now=x,dd[4];
		for(int i=0;i<4;++i){
			dd[i]=now%10;
			now/=10;
		}
		for(int k=0;k<4;++k){
			int st=0;
			if(k==3)st=1;
			for(int i=st;i<=9;++i){
				int nxt=x-dd[k]*mp[k];
				nxt+=i*mp[k];
				if(d[nxt]==-1){
					if(!v[nxt]){
						d[nxt]=d[x]+1;
						q.push(nxt);
					}
				}
			}
		}
	}
}
int main(){
	mp[0]=1;mp[1]=10;mp[2]=100;mp[3]=1000;
	cin>>t;
	init();
	while(t--){
		scanf("%d%d",&a,&b);
		bfs();
		if(d[b]==-1)puts("Impossible");
		else cout<<d[b]<<"\n";
	}
	return 0;
}