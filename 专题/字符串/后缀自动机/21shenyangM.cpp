#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=2e6+5;
int L;
vector<int>G[maxn];
struct SAM{
	int len[maxn],link[maxn],ch[maxn][26],last,tot,pos[maxn],ans[maxn];
	bool vis[maxn];
	SAM(){
		tot=last=1;
	}
	void extend(int c,int id){
		int cur=++tot,p=last;last=cur;pos[cur]=id;
		len[cur]=len[p]+1;
		for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
		if(!p)link[cur]=1;
		else{
			int q=ch[p][c];
			if(len[p]+1==len[q])link[cur]=q;
			else{
				int clone=++tot;
				memcpy(ch[clone],ch[q],sizeof(ch[q]));
				len[clone]=len[p]+1;
				link[clone]=link[q];link[q]=link[cur]=clone;
				pos[clone]=pos[q];
				for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
			}
		}
	}

	void dfs(int x,int len){
		vis[x]=1;
		for(int i=25;i>=0;--i){
			int nxt=ch[x][i];
			if(vis[nxt]||!nxt)continue;
			dfs(nxt,len+1);
		}
		if(!ans[pos[x]])
			ans[pos[x]]=pos[x]-len+1;
	}
	void solve(){
		dfs(1,0);
		for(int i=1;i<=L;++i)
			cout<<ans[i]<<" "<<i<<"\n";
	}
}sam;
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	L=strlen(s+1);
	for(int i=1;i<=L;++i){
		sam.extend(s[i]-'a',i);
	}
	//cout<<sam.tot<<'\n';
	sam.solve();
	return 0;
}