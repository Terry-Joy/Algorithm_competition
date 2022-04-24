#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll head[maxn],nex[maxn<<1],edge[maxn<<1],cnt,ver[maxn<<1],sz[maxn],n;
ll ans=0;
int k;
void add(int a,int b,int c){
	ver[++cnt]=b,edge[cnt]=c;nex[cnt]=head[a];head[a]=cnt;
}
void dfs(int now,int fa){
	sz[now]=1;
	for(int i=head[now];i;i=nex[i]){
		int y=ver[i];
		if(y==fa)continue;
		dfs(y,now);
		sz[now]+=sz[y];
	}
    int num=0;
    for(int i=head[now];i;i=nex[i]){ 
        int y=ver[i];
        if(y==fa)num=max(1ll*num,n-sz[now]);
        else num=max(1ll*num,sz[y]);
    }
    int w=(n-k)/2;
    if(num-k<=w)ans++;
} 
int main(){
	int t,x,y;
	cin>>t;
	int i=0;
	while(t--){
        ans=0;
		scanf("%d%d",&n,&k);
		memset(head,0,sizeof(head));
		cnt=ans=0;
		for(int i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			add(x,y,1);
			add(y,x,1);
		}
		dfs(1,0);
        printf("Case #%d: %lld\n",++i,ans);
	}
	return 0;
}
